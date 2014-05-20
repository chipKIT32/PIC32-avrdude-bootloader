/************************************************************************/
/*                                                                      */
/*  ViewHeaderInfo.cpp -- View MPIDE and bootloader header info         */
/*                                                                      */
/************************************************************************/
/*    Author:     Keith Vogel                                           */
/*    Copyright 2012, Digilent Inc., All Rights Reserved                */
/************************************************************************/
/*
*
* Copyright (c) 2013-2014, Digilent <www.digilentinc.com>
* Contact Digilent for the latest version.
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
/************************************************************************/
/*  Module Description:                                                 */
/*                                                                      */
/*                                                                      */
/*  Revision History:                                                   */
/*                                                                      */
/*    09/28/2012(KeithV): Created                                       */
/*                                                                      */
/************************************************************************/

extern const uint32_t _IMAGE_HEADER_ADDR;   

static const IMAGE_HEADER_INFO * pImageHeader = getImageHeaderInfoStructure();            

void setup() {       

    // initialize the digital pin as an output.
    // Pin 13 has an LED connected on most Arduino boards:
    pinMode(PIN_LED1, OUTPUT); 
  
    Serial.begin(9600);

    #if defined(_USE_USB_FOR_SERIAL_)
    // the 3 second delay is put in for boards that use USB serial to allow time to open the serial monitor
    delay(3000);
    #endif

    Serial.println("Primary Image pointers:");
    Serial.println("_IMAGE_HEADER_ADDR");     
    Serial.println((uint32_t) &_IMAGE_HEADER_ADDR, HEX);
    Serial.println(_IMAGE_HEADER_ADDR, HEX);
    Serial.println();

    Serial.println("Flash Header Info:");
    Serial.println();

    Serial.print("cbHeader: ");
    Serial.println(pImageHeader->cbHeader, DEC);

    Serial.print("Bootloader Version: 0x");
    Serial.println(pImageHeader->verBootloader, HEX);

    Serial.print("MPIDE Version: 0x");
    Serial.println(pImageHeader->verMPIDE, HEX);

    Serial.print("Bootloader Capabilities: 0x");
    Serial.println(pImageHeader->bootloaderCapabilities, HEX);

    Serial.print("Vendor ID: 0x");
    Serial.println(pImageHeader->vend, HEX);

    Serial.print("Product ID: 0x");
    Serial.println(pImageHeader->prod, HEX);

    Serial.print("Image Type: 0x");
    Serial.println((uint32_t) pImageHeader->imageType, HEX);

    Serial.print("Execution Start Address: 0x");
    Serial.println((uint32_t) pImageHeader->pJumpAddr, HEX);

    Serial.print("Program Flash Base Address: 0x");
    Serial.println(pImageHeader->pProgramFlash, HEX);

    Serial.print("Length of Program Flash: 0x");
    Serial.println(pImageHeader->cbProgramFlash, HEX);

    Serial.print("EEProm Address: 0x");
    Serial.println(pImageHeader->pEEProm, HEX);

    Serial.print("Length of EEProm: 0x");
    Serial.println(pImageHeader->cbEEProm, HEX);

    Serial.print("Config Bit Address: 0x");
    Serial.println(pImageHeader->pConfig, HEX);

    Serial.print("Length of Config Bits: 0x");
    Serial.println(pImageHeader->cbConfig, HEX);

    Serial.print("Address of Ram Header as placed by the sketch's linker script: 0x");
    Serial.println((uint32_t) pImageHeader->pRamHeader, HEX);

    Serial.print("Length of Ram Header as known by the linker script: ");
    Serial.println(pImageHeader->cbRamHeader, DEC);

    Serial.print("The max amount of RAM reserved for Debug data, Ram header, and persistent data as preserved by the bootloader: 0x");
    Serial.println((uint32_t) pImageHeader->cbBlPreservedRam, HEX);

    Serial.println();

    Serial.println("Ram Header Info:");
    Serial.println();

    Serial.print("Amount of Ram Header written by the bootloader: ");
    Serial.println(pImageHeader->pRamHeader->cbBlRamHeader, DEC);

    Serial.print("RCON value before bootloader execution: 0x");
    Serial.println(pImageHeader->pRamHeader->rcon, HEX);
  }

void loop() {
  digitalWrite(PIN_LED1, HIGH);   // set the LED on
  delay(1000);              // wait for a second
  digitalWrite(PIN_LED1, LOW);    // set the LED off
  delay(1000);              // wait for a second
}
