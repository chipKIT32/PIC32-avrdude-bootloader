/**** usb.c *******************************************************************
 *
 * this file implements a generic usb device driver; the CDC/ACM transport
 * sits on top of this module to implement a specific usb device function.
 *
 * This file originated from the cpustick.com skeleton project from
 * http://www.cpustick.com/downloads.htm and was originally written
 * by Rich Testardi; please preserve this reference and share bug
 * fixes with rich@testardi.com.
 * Copyright 2014 Rich Testardi
 *
 * This program is free software; distributed under the terms of
 * BSD 3-clause license ("Revised BSD License", "New BSD License", or "Modified BSD License")
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1.    Redistributions of source code must retain the above copyright notice, this
 *        list of conditions and the following disclaimer.
 * 2.    Redistributions in binary form must reproduce the above copyright notice,
 *        this list of conditions and the following disclaimer in the documentation
 *        and/or other materials provided with the distribution.
 * 3.    Neither the name(s) of the above-listed copyright holder(s) nor the names
 *        of its contributors may be used to endorse or promote products derived
 *        from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
#include "main.h"

// XXX -- move to relocated compat.h
#define MCF_USB_OTG_CTL  U1CON
#define MCF_USB_OTG_CTL_USB_EN_SOF_EN  _U1CON_SOFEN_MASK
#define MCF_USB_OTG_OTG_CTRL  U1OTGCON
#define MCF_USB_OTG_OTG_CTRL_DP_HIGH  _U1OTGCON_DPPULUP_MASK
#define MCF_USB_OTG_OTG_CTRL_OTG_EN  _U1OTGCON_OTGEN_MASK
#define MCF_USB_OTG_INT_STAT  U1IR
#define MCF_USB_OTG_INT_ENB  U1IE
#define MCF_USB_OTG_INT_ENB_USB_RST_EN  _U1IE_URSTIE_MASK
#define MCF_USB_OTG_ADDR  U1ADDR
#define MCF_USB_OTG_CTL_ODD_RST  _U1CON_PPBRST_MASK
#define MCF_USB_OTG_INT_ENB_SLEEP_EN  _U1IE_IDLEIE_MASK
#define MCF_USB_OTG_INT_ENB_TOK_DNE_EN  _U1IE_TRNIE_MASK
#define MCF_USB_OTG_ENDPT_EP_HSHK  _U1EP0_EPHSHK_MASK
#define MCF_USB_OTG_ENDPT_EP_TX_EN  _U1EP0_EPTXEN_MASK
#define MCF_USB_OTG_ENDPT_EP_RX_EN  _U1EP0_EPRXEN_MASK
#define MCF_USB_OTG_ENDPT_EP_CTL_DIS  _U1EP0_EPCONDIS_MASK
#define MCF_USB_OTG_INT_STAT_TOK_DNE  _U1IR_TRNIF_MASK
#define MCF_USB_OTG_STAT  U1STAT
#define MCF_USB_OTG_STAT_TX  _U1STAT_DIR_MASK
#define MCF_USB_OTG_STAT_ODD  _U1STAT_PPBI_MASK
#define MCF_USB_OTG_CTL_TXSUSPEND_TOKENBUSY  _U1CON_TOKBUSY_MASK
#define MCF_USB_OTG_INT_STAT_USB_RST  _U1IR_URSTIF_MASK
#define MCF_USB_OTG_INT_STAT_SLEEP  _U1IR_IDLEIF_MASK
#define MCF_USB_OTG_SOF_THLD  U1SOF
#define MCF_USB_OTG_BDT_PAGE_01  U1BDTP1
#define MCF_USB_OTG_BDT_PAGE_02  U1BDTP2
#define MCF_USB_OTG_BDT_PAGE_03  U1BDTP3

#define MCF_USB_OTG_TOKEN  U1TOK
#define MCF_USB_OTG_ENDPT0  U1EP0
#define MCF_USB_OTG_ENDPT_RETRY_DIS  _U1EP0_RETRYDIS_MASK
#define MCF_USB_OTG_CTL_HOST_MODE_EN  _U1CON_HOSTEN_MASK
#define MCF_USB_OTG_OTG_CTRL_DM_LOW  _U1OTGCON_DMPULDWN_MASK
#define MCF_USB_OTG_OTG_CTRL_DP_LOW  _U1OTGCON_DPPULDWN_MASK
#define MCF_USB_OTG_INT_ENB_ATTACH_EN  _U1IE_ATTACHIE_MASK
#define MCF_USB_OTG_INT_STAT_ATTACH  _U1IR_ATTACHIF_MASK
#define MCF_USB_OTG_CTL_JSTATE  _U1CON_JSTATE_MASK
#define MCF_USB_OTG_ADDR_LS_EN  _U1ADDR_LSPDEN_MASK
#define MCF_USB_OTG_CTL_RESET  _U1CON_USBRST_MASK
#define MCF_USB_OTG_INT_STAT_RESUME  _U1IR_RESUMEIF_MASK
#define MCF_USB_OTG_ENDPT_HOST_WO_HUB  _U1EP0_LSPD_MASK
#define MCF_USB_OTG_TOKEN_TOKEN_PID(x)  ((x)<<_U1TOK_PID0_POSITION)
#define MCF_USB_OTG_TOKEN_TOKEN_ENDPT(x)  ((x)<<_U1TOK_EP0_POSITION)
#define MCF_USB_OTG_INT_STAT_ERROR  _U1IE_UERRIE_MASK

/*
#define KVA_TO_PA(v)  ((v) & 0x1fffffff)
#define PA_TO_KVA0(pa)  ((pa) | 0x80000000)  // cachable
#define PA_TO_KVA1(pa)  ((pa) | 0xa0000000)
*/

#define HWRETRIES  1
#define SWRETRIES  3

#define DEVICE_DESCRIPTOR_SIZE  18
#define CONFIGURATION_DESCRIPTOR_SIZE  128

#define BULK_ATTRIBUTES  2
#define INTERRUPT_ATTRIBUTES  3

#define FEATURE_ENDPOINT_HALT  0x00

#define TOKEN_OUT  0x01
#define TOKEN_ACK  0x02
#define TOKEN_DATA0  0x03
#define TOKEN_IN  0x09
#define TOKEN_NAK  0x0a
#define TOKEN_DATA1  0x0b
#define TOKEN_SETUP  0x0d

#define CLASS_CDC  0x02
#define CLASS_SCSI  0x08

#define BD_FLAGS_BC_ENC(x)  (((x) & 0x3ff) << 16)
#define BD_FLAGS_BC_DEC(y)  (((y) & 0x3ff0000) >> 16)
#define BD_FLAGS_OWN  0x80
#define BD_FLAGS_DATA  0x40
#define BD_FLAGS_DTS  0x08
#define BD_FLAGS_TOK_PID_DEC(y)  (((y) & 0x3c) >> 2)

#define MYBDT(endpoint, tx, odd)  (bdts+(endpoint)*4+(tx)*2+(odd))

#define BDT_RAM_SIZE  256

static struct bdt {
    int flags;
    byte *buffer;
} *bdts;  // 512 byte aligned in buffer

// N.B. only bdt endpoint 0 is used for host mode!

#define ENDPOINTS  4

struct endpoint {
    byte toggle[2];  // rx [0] and tx [1] next packet data0 (0) or data1 (BD_FLAGS_DATA)
    byte bdtodd[2];  // rx [0] and tx [1] next bdt even (0) or odd (1)
    byte packetsize;
    bool inter;

    byte data_pid;  // TOKEN_IN -> data to host; TOKEN_OUT -> data from host
    int data_offset;  // current offset in data stream
    int data_length;  // max offset in data stream
    byte data_buffer[80];  // data to or from host
} endpoints[ENDPOINTS];

byte bulk_in_ep;
byte bulk_out_ep;
byte int_ep;

#if SODEBUG
volatile bool usb_in_isr;
#endif

bool cdc_attached;  // set when cdc acm device is attached
bool scsi_attached;  // set when usb mass storage device is attached
uint32 scsi_attached_count;
bool other_attached;  // set when other device is attached

bool cdcacm_attached;  // set when cdcacm host is attached
uint32 cdcacm_attached_count;

static bool usb_initalized = false;	// used to track if we need to uninit or not

static
void
parse_configuration(const byte *configuration, int size)
{
    int i;

    // extract the bulk endpoint information
    for (i = 0; i < size; i += configuration[i]) {
        if (configuration[i+1] == ENDPOINT_DESCRIPTOR) {
            if (configuration[i+3] == BULK_ATTRIBUTES) {
                if (configuration[i+2] & 0x80) {
                    bulk_in_ep = (byte)(configuration[i+2] & 0xf);
                    assert(bulk_in_ep < LENGTHOF(endpoints));
                    assert(configuration[i+4]);
                    endpoints[bulk_in_ep].packetsize = configuration[i+4];
                } else {
                    bulk_out_ep = (byte)(configuration[i+2] & 0xf);
                    assert(bulk_out_ep < LENGTHOF(endpoints));
                    assert(configuration[i+4]);
                    endpoints[bulk_out_ep].packetsize = configuration[i+4];
                }
            } else if (configuration[i+3] == INTERRUPT_ATTRIBUTES) {
                int_ep = (byte)(configuration[i+2] & 0xf);
                assert(int_ep < LENGTHOF(endpoints));
                assert(configuration[i+4]);
                endpoints[int_ep].packetsize = configuration[i+4];
                endpoints[int_ep].inter = 1;
            }
        }
    }
    assert(i == size);
}

// *** device ***

static const byte *device_descriptor;
static int device_descriptor_length;

static const byte *configuration_descriptor;
static int configuration_descriptor_length;

static const byte *string_descriptor;
static int string_descriptor_length;

static usb_reset_cbfn reset_cbfn;
static usb_control_cbfn control_transfer_cbfn;
static usb_bulk_cbfn bulk_transfer_cbfn;

// this function puts our state machine in a waiting state, waiting
// for a usb reset from the host.
static
void
usb_device_wait()
{
    // enable usb device mode
    MCF_USB_OTG_CTL = MCF_USB_OTG_CTL_USB_EN_SOF_EN;

    // enable usb pull ups
    MCF_USB_OTG_OTG_CTRL = MCF_USB_OTG_OTG_CTRL_DP_HIGH|MCF_USB_OTG_OTG_CTRL_OTG_EN;

    // enable (only) usb reset interrupt
    MCF_USB_OTG_INT_STAT = 0xff;
    MCF_USB_OTG_INT_ENB = MCF_USB_OTG_INT_ENB_USB_RST_EN;
}

// this function puts our state machine into the default state,
// waiting for a "set configuration" command from the host.
static
void
usb_device_default()
{
    // default to address 0 on reset
    MCF_USB_OTG_ADDR = (uint8)0;

    // enable usb device mode
    MCF_USB_OTG_CTL |= MCF_USB_OTG_CTL_ODD_RST;
    MCF_USB_OTG_CTL &= ~MCF_USB_OTG_CTL_ODD_RST;

    ilmemset(bdts, 0, BDT_RAM_SIZE);
    ilmemset(endpoints, 0, sizeof(endpoints));

    assert(configuration_descriptor);

    // extract the maximum packet size from the device descriptor
    endpoints[0].packetsize = device_descriptor[7];

    // parse the configuration descriptor
    parse_configuration(configuration_descriptor, configuration_descriptor_length);

    // enable (also) usb sleep and token done interrupts
    MCF_USB_OTG_INT_STAT = 0xff;
    MCF_USB_OTG_INT_ENB |= MCF_USB_OTG_INT_ENB_SLEEP_EN|MCF_USB_OTG_INT_ENB_TOK_DNE_EN;
}

// enqueue a packet to the usb engine for transfer to/from the host
void
usb_device_enqueue(int endpoint, bool tx, byte *buffer, int length)
{
    int ep;
    bool odd;
    int flags;
    volatile struct bdt *bdt;

    assert(endpoint < LENGTHOF(endpoints));

    if (tx != (bool)-1) {
        // transfer up to one packet at a time
        assert(endpoints[endpoint].packetsize);
        length = MIN(length, endpoints[endpoint].packetsize);

        // find the next bdt entry to use
        odd = endpoints[endpoint].bdtodd[tx];

        // initialize the bdt entry
        bdt = MYBDT(endpoint, tx, odd);
        bdt->buffer = (byte *)TF_LITTLE(KVA_2_PA((int)buffer));
        flags = TF_LITTLE(bdt->flags);
        assert(! (flags & BD_FLAGS_OWN));
        assert(length <= endpoints[endpoint].packetsize);
        bdt->flags = TF_LITTLE(BD_FLAGS_BC_ENC(length)|BD_FLAGS_OWN|endpoints[endpoint].toggle[tx]|BD_FLAGS_DTS);
    }

    ep = MCF_USB_OTG_ENDPT_EP_HSHK|MCF_USB_OTG_ENDPT_EP_TX_EN|MCF_USB_OTG_ENDPT_EP_RX_EN;
    ep |= endpoint?MCF_USB_OTG_ENDPT_EP_CTL_DIS:0;
    // enable the packet transfer
    switch (endpoint) {
        case 0:
            U1EP0 = (uint8)(ep);
            break;
        case 1:
            U1EP1 = (uint8)(ep);
            break;
        case 2:
            U1EP2 = (uint8)(ep);
            break;
        case 3:
            U1EP3 = (uint8)(ep);
            break;
        default:
            ASSERT(0);
            break;
    }
}

static byte setup_buffer[SETUP_SIZE];  // from host
static byte next_address;  // set after successful status

// *** isr ***

static byte descriptor[DEVICE_DESCRIPTOR_SIZE];
static byte configuration[CONFIGURATION_DESCRIPTOR_SIZE];

// called by usb on device attach
#if INTERRUPT
__ISR(45, ipl6) // XXX -- _USB_1_VECTOR, ipl?
#endif
void
usb_isr(void)
{
    int rv;

    if (! bdts) {
        return;  // XXX
    }
    
    assert(! usb_in_isr);
    assert((usb_in_isr = true) ? true : true);
    
#if INTERRUPT
    IFS1CLR = 0x02000000; // USBIF
#endif
    
    // *** device ***
    
    // if we just transferred a token...
    if (MCF_USB_OTG_INT_STAT & MCF_USB_OTG_INT_STAT_TOK_DNE) {
        int bc;
        int tx;
        int odd;
        int pid;
        int stat;
        int flags;
        byte *data;
        int endpoint;
        int endpoint2;
        short length;
        short value;
        volatile struct bdt *bdt;
        struct setup *setup;
        
        // we just completed a packet transfer
        stat = MCF_USB_OTG_STAT;
        tx = !! (stat & MCF_USB_OTG_STAT_TX);
        odd = !! (stat & MCF_USB_OTG_STAT_ODD);
        endpoint = (stat & 0xf0) >> 4;

        // toggle the data toggle flag
        endpoints[endpoint].toggle[tx] = endpoints[endpoint].toggle[tx] ? 0 : BD_FLAGS_DATA;
        
        // toggle the next bdt entry to use
        ASSERT(odd == endpoints[endpoint].bdtodd[tx]);
        endpoints[endpoint].bdtodd[tx] = ! endpoints[endpoint].bdtodd[tx];

        bdt = MYBDT(endpoint, tx, odd);

        flags = TF_LITTLE(bdt->flags);
        assert(! (flags & BD_FLAGS_OWN));

        bc = BD_FLAGS_BC_DEC(flags);
        assert(bc >= 0);

        pid = BD_FLAGS_TOK_PID_DEC(flags);

        // if we're starting a new control transfer...
        if (pid == TOKEN_SETUP) {
            assert(! endpoint);
            assert(bc == 8);
            assert(! tx);

            setup = (struct setup *)TF_LITTLE((int)PA_2_KVA1((int)bdt->buffer));
            assert((void *)setup == (void *)setup_buffer);

            // unsuspend the usb packet engine
            MCF_USB_OTG_CTL &= ~MCF_USB_OTG_CTL_TXSUSPEND_TOKENBUSY;

            length = TF_LITTLE(setup->length);

            endpoints[endpoint].data_pid = TOKEN_OUT;
            endpoints[endpoint].data_length = 0;
            endpoints[endpoint].data_offset = 0;

            // is this a standard command...
            if (! (setup->requesttype & 0x60)) {
                value = TF_LITTLE(setup->value);
                if (setup->request == REQUEST_GET_DESCRIPTOR) {
                    endpoints[endpoint].data_pid = TOKEN_IN;

                    if ((value >> 8) == DEVICE_DESCRIPTOR) {
                        assert(device_descriptor_length);
                        endpoints[endpoint].data_length = MIN(device_descriptor_length, length);
                        ilmemcpy(endpoints[endpoint].data_buffer, device_descriptor, endpoints[endpoint].data_length);
                    } else if ((value >> 8) == CONFIGURATION_DESCRIPTOR) {
                        assert(configuration_descriptor_length);
                        endpoints[endpoint].data_length = MIN(configuration_descriptor_length, length);
                        ilmemcpy(endpoints[endpoint].data_buffer, configuration_descriptor, endpoints[endpoint].data_length);
                    } else if ((value >> 8) == STRING_DESCRIPTOR) {
                        int i;
                        int j;

                        // find the string descriptor
                        i = value & 0xff;
                        j = 0;
                        while (i-- && j < string_descriptor_length) {
                            j += string_descriptor[j];
                        }
                        if (i != -1) {
                            assert(j == string_descriptor_length);
                            endpoints[endpoint].data_length = 0;  // what to return here?
                        } else {
                            assert(string_descriptor[j]);
                            endpoints[endpoint].data_length = MIN(string_descriptor[j], length);
                            ilmemcpy(endpoints[endpoint].data_buffer, string_descriptor+j, endpoints[endpoint].data_length);
                        }
                    } else if ((value >> 8) == DEVICE_QUALIFIER_DESCRIPTOR) {
                        endpoints[endpoint].data_length = 0;
                    } else {
                        assert(0);
                    }

                    // data phase starts with data1
                    assert(endpoints[endpoint].toggle[1] == BD_FLAGS_DATA);
                    usb_device_enqueue(0, 1, endpoints[endpoint].data_buffer, MIN(endpoints[endpoint].data_length, endpoints[endpoint].packetsize));
                } else {
                    if (setup->request == REQUEST_CLEAR_FEATURE) {
                        assert(! length);
                        // if we're recovering from an error...
                        if (setup->requesttype == 0x02 && ! value) {
                            endpoint2 = TF_LITTLE(setup->index) & 0x0f;
                            assert(endpoint2);
                            // clear the data toggle
                            endpoints[endpoint2].toggle[0] = 0;
                            endpoints[endpoint2].toggle[1] = 0;
                        } else {
                            assert(0);
                        }
                    } else if (setup->request == REQUEST_SET_ADDRESS) {
                        next_address = value;
                    } else if (setup->request == REQUEST_SET_CONFIGURATION) {
                        assert(value == 1);
                        cdcacm_attached_count++;
                        cdcacm_attached = 1;
                    } else if (setup->request == REQUEST_GET_CONFIGURATION) {
                        endpoints[endpoint].data_pid = TOKEN_IN;

                        endpoints[endpoint].data_length = 1;
                        endpoints[endpoint].data_buffer[0] = 1;

                        // data phase starts with data1
                        assert(endpoints[endpoint].toggle[1] == BD_FLAGS_DATA);
                        usb_device_enqueue(0, 1, endpoints[endpoint].data_buffer, MIN(endpoints[endpoint].data_length, endpoints[endpoint].packetsize));
                        goto XXX_SKIP2_XXX;
                    } else {
                        assert(0);
                    }

                    // prepare to transfer status (in the other direction)
                    usb_device_enqueue(0, 1, NULL, 0);
XXX_SKIP2_XXX:;
                }
            // otherwise, this is a class or vendor command
            } else {
                if (setup->requesttype & 0x80/*in*/) {
                    // host wants to receive data, get it from our caller!
                    assert(control_transfer_cbfn);
                    rv = control_transfer_cbfn(setup, endpoints[endpoint].data_buffer, length);
                    assert(rv >= 0);
                    assert(rv <= length);

                    // prepare to send data, TOKEN_IN(s) will follow
                    endpoints[endpoint].data_pid = TOKEN_IN;
                    assert(rv > 0);  // if you don't have a length, use out!
                    endpoints[endpoint].data_length = rv;
                    usb_device_enqueue(0, 1, endpoints[endpoint].data_buffer, endpoints[endpoint].data_length);
                } else {
                    // host is sending data
                    if (length) {
                        // we will receive data, TOKEN_OUT(s) will follow
                        endpoints[endpoint].data_length = length;
                        usb_device_enqueue(0, 0, endpoints[endpoint].data_buffer, endpoints[endpoint].packetsize);
                    } else {
                        // data transfer is done; put it to our caller!
                        assert(control_transfer_cbfn);
                        rv = control_transfer_cbfn((struct setup *)setup_buffer, NULL, 0);
                        assert(rv != -1);

                        // status uses data1
                        assert(endpoints[endpoint].toggle[1] == BD_FLAGS_DATA);

                        // prepare to transfer status (in the other direction)
                        usb_device_enqueue(0, 1, NULL, 0);
                    }
                }
            }
            assert((unsigned)endpoint < LENGTHOF(endpoints));
            assert(endpoints[endpoint].data_length <= sizeof(endpoints[endpoint].data_buffer));
        } else if (! endpoint) {
            assert(pid == TOKEN_IN || pid == TOKEN_OUT);
            data = (byte *)TF_LITTLE((int)PA_2_KVA1((int)bdt->buffer));

            // if this is part of the data transfer...
            if (pid == endpoints[endpoint].data_pid) {
                assert((char *)data >= (char *)endpoints[endpoint].data_buffer && (char *)data < (char *)endpoints[endpoint].data_buffer+sizeof(endpoints[endpoint].data_buffer));
                if (pid == TOKEN_IN) {
                    assert(tx);
                    // we just sent data to the host
                    endpoints[endpoint].data_offset += bc;
                    assert(endpoints[endpoint].data_offset <= endpoints[endpoint].data_length);

                    // if there's more data to send...
                    if (endpoints[endpoint].data_offset != endpoints[endpoint].data_length) {
                        // send it
                        usb_device_enqueue(0, 1, endpoints[endpoint].data_buffer+endpoints[endpoint].data_offset, endpoints[endpoint].data_length-endpoints[endpoint].data_offset);
                    } else {
                        // status uses data1
                        assert(endpoints[endpoint].toggle[0] == BD_FLAGS_DATA);

                        // prepare to transfer status (in the other direction)
                        usb_device_enqueue(0, 0, NULL, 0);
                    }
                } else {
                    assert(! tx);
                    // we just received data from the host
                    endpoints[endpoint].data_offset += bc;
                    assert(endpoints[endpoint].data_offset <= endpoints[endpoint].data_length);

                    // if there's more data to receive...
                    if (endpoints[endpoint].data_offset != endpoints[endpoint].data_length) {
                        // receive it
                        usb_device_enqueue(0, 0, endpoints[endpoint].data_buffer+endpoints[endpoint].data_offset, endpoints[endpoint].data_length-endpoints[endpoint].data_offset);
                    } else {
                        // put it to our caller!
                        assert(control_transfer_cbfn);
                        rv = control_transfer_cbfn((struct setup *)setup_buffer, endpoints[endpoint].data_buffer, endpoints[endpoint].data_length);
                        assert(rv != -1);

                        // status uses data1
                        assert(endpoints[endpoint].toggle[1] == BD_FLAGS_DATA);

                        // prepare to transfer status (in the other direction)
                        usb_device_enqueue(0, 1, NULL, 0);
                    }
                }
            // otherwise; we just transferred status
            } else {
                assert(data == PA_TO_KVA1(0));

                // update our address after status
                if (next_address) {
                    MCF_USB_OTG_ADDR |= next_address;
                    next_address = 0;
                }

                // setup always uses data0; following transactions start with data1
                endpoints[endpoint].toggle[0] = 0;
                endpoints[endpoint].toggle[1] = BD_FLAGS_DATA;

                // prepare to receive setup token
                usb_device_enqueue(0, 0, setup_buffer, sizeof(setup_buffer));
            }
        } else if (endpoint != int_ep) {
            assert(pid == TOKEN_IN || pid == TOKEN_OUT);
            data = (byte *)TF_LITTLE((int)PA_2_KVA1((int)bdt->buffer));

            // we just received or sent data from or to the host
            assert(bulk_transfer_cbfn);
            bulk_transfer_cbfn(pid == TOKEN_IN, data, bc);
        }

        MCF_USB_OTG_INT_STAT = MCF_USB_OTG_INT_STAT_TOK_DNE;
    }

    // if we just got reset by the host...
    if (MCF_USB_OTG_INT_STAT & MCF_USB_OTG_INT_STAT_USB_RST) {
        cdcacm_active = 0;
        cdcacm_attached = 0;

        usb_device_default();

        assert(reset_cbfn);
        reset_cbfn();

        // setup always uses data0; following transactions start with data1
        endpoints[0].toggle[0] = 0;
        endpoints[0].toggle[1] = BD_FLAGS_DATA;

        // prepare to receive setup token
        usb_device_enqueue(0, 0, setup_buffer, sizeof(setup_buffer));

        MCF_USB_OTG_INT_STAT = MCF_USB_OTG_INT_STAT_USB_RST;
    }

    // if we just went idle...
    if (MCF_USB_OTG_INT_STAT & MCF_USB_OTG_INT_STAT_SLEEP) {
        cdcacm_active = 0;
        cdcacm_attached = 0;

        // disable usb sleep interrupts
        MCF_USB_OTG_INT_ENB &= ~MCF_USB_OTG_INT_ENB_SLEEP_EN;
        MCF_USB_OTG_INT_STAT = MCF_USB_OTG_INT_STAT_SLEEP;
    }
    
XXX_SKIP_XXX:
    assert(usb_in_isr);
    assert((usb_in_isr = false) ? true : true);
}

// this function is called by upper level code to register callback
// functions.
void
usb_register(usb_reset_cbfn reset, usb_control_cbfn control_transfer, usb_bulk_cbfn bulk_transfer)
{
    reset_cbfn = reset;
    control_transfer_cbfn = control_transfer;
    bulk_transfer_cbfn = bulk_transfer;
}

// called by upper level code to specify the device descriptor to
// return to the host.
void
usb_device_descriptor(const byte *descriptor, int length)
{
    device_descriptor = descriptor;
    device_descriptor_length = length;
}

// called by upper level code to specify the configuration descriptor
// to return to the host.
void
usb_configuration_descriptor(const byte *descriptor, int length)
{
    configuration_descriptor = descriptor;
    configuration_descriptor_length = length;
}

// called by upper level code to specify the string descriptors to
// return to the host.
void
usb_string_descriptor(const byte *descriptor, int length)
{
    string_descriptor = descriptor;
    string_descriptor_length = length;
}

void
usb_uninitialize(void)
{
    int i;
    uint32 tStart;
    
    if (!usb_initalized)
    	return;
    
    // Sync the two LEDs for tamdom toggling
    BootLED_Off();
    DownloadLED_Off();

    // wait for the USB interface to send the 
    // final ACK packects. We must poll the usb isr
    // routine to process this stuff.

    // We want to toggle the boot and download leds 8 times per second
    // and we what about 2 seconds of waiting, or 16 * 1/8 sec time frames.
    for(i=0; i< 16; i++)
    {
        BootLED_Toggle();
        DownloadLED_Toggle();

        tStart = _CP0_GET_COUNT();
        do
        {
            usb_isr();
        } while((_CP0_GET_COUNT() - tStart) <= (CORE_TIMER_TICKS_PER_MILLISECOND * 125));
    }

    // disable usb device mode and usb device pull ups
    MCF_USB_OTG_CTL = 0;
    MCF_USB_OTG_OTG_CTRL = 0;

    // power off
    U1PWRCbits.USBPWR = 0;

    DownloadLED_Off();

    // Now we need to wait for the USB to shut down cleanly
    // before jumping to the app and abruptly terminating.
    // we need to wait for about 1/2 second or 500ms
    tStart = _CP0_GET_COUNT();
    do
    {
        BootLED_Toggle();       // this is a very fast toggle, so the LED will appear 1/2 power
    } while((_CP0_GET_COUNT() - tStart) <= (CORE_TIMER_TICKS_PER_MILLISECOND * 500));
 }

void
usb_initialize(void)
{
    static __attribute__ ((aligned(512))) byte bdt_ram[BDT_RAM_SIZE];

    bdts = (struct bdt *)bdt_ram;

    assert(BDT_RAM_SIZE >= LENGTHOF(endpoints)*4*sizeof(struct bdt));

    // power on
    U1PWRCbits.USBPWR = 1;

    // enable int
#if INTERRUPT
    IEC1bits.USBIE = 1;
    IPC11bits.USBIP = 6;
    IPC11bits.USBIS = 0;
#endif

    MCF_USB_OTG_SOF_THLD = 74;

    // initialize usb bdt
    assert(! ((unsigned int)bdts & 0x1ff));
    MCF_USB_OTG_BDT_PAGE_01 = (uint8)(KVA_2_PA((unsigned int)bdts) >> 8);
    MCF_USB_OTG_BDT_PAGE_02 = (uint8)(KVA_2_PA((unsigned int)bdts) >> 16);
    MCF_USB_OTG_BDT_PAGE_03 = (uint8)(KVA_2_PA((unsigned int)bdts) >> 24);

    // enable usb to interrupt on reset
    usb_device_wait();
    
    usb_initalized = true;
}
