/**** usb.h *******************************************************************
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
#define SETUP_SIZE  8

#define SETUP_TYPE_STANDARD  0
#define SETUP_TYPE_CLASS  1
#define SETUP_TYPE_VENDOR  2

#define SETUP_RECIP_DEVICE  0
#define SETUP_RECIP_INTERFACE  1
#define SETUP_RECIP_ENDPOINT  2

#define REQUEST_CLEAR_FEATURE  0x01
#define REQUEST_SET_ADDRESS  0x05
#define REQUEST_GET_DESCRIPTOR  0x06
#define REQUEST_GET_CONFIGURATION  0x08
#define REQUEST_SET_CONFIGURATION  0x09

#define DEVICE_DESCRIPTOR  1
#define CONFIGURATION_DESCRIPTOR  2
#define STRING_DESCRIPTOR  3
#define ENDPOINT_DESCRIPTOR  5
#define DEVICE_QUALIFIER_DESCRIPTOR  6

#define TOKEN_STALL  0x0e  // for mst stall disaster

struct setup {
    byte requesttype;  // 7:in, 6-5:type, 4-0:recip
    byte request;
    short value;
    short index;
    short length;
};

extern volatile bool usb_in_isr;  // set when in isr

extern bool cdcacm_attached;  // set when cdcacm host is attached
extern uint32 cdcacm_attached_count;

extern byte bulk_in_ep;
extern byte bulk_out_ep;
extern byte int_ep;

// *** device ***

// enqueue a packet to the usb engine for transfer to/from the host
void
usb_device_enqueue(int endpoint, bool tx, byte *buffer, int length);

typedef void (*usb_reset_cbfn)(void);
typedef int (*usb_control_cbfn)(struct setup *setup, byte *buffer, int length);
typedef int (*usb_bulk_cbfn)(bool in, byte *buffer, int length);
typedef void (*usb_interrupt_cbfn)(void);

void
usb_register(usb_reset_cbfn reset, usb_control_cbfn control_transfer, usb_bulk_cbfn bulk_transfer);

void
usb_device_descriptor(const byte *descriptor, int length);

void
usb_configuration_descriptor(const byte *descriptor, int length);

void
usb_string_descriptor(const byte *descriptor, int length);

// *** init ***

#if ! INTERRUPT
void
usb_isr(void);
#endif

void
usb_uninitialize(void);

void
usb_initialize(void);

