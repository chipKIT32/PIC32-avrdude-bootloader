/************************************************************************/
/*                                                                      */
/*  ViewHeaderInfo.cpp -- View MPIDE and bootloader header info         */
/*                                                                      */
/************************************************************************/
/*    Author:     Keith Vogel                                           */
/*    Copyright 2012, Digilent Inc., All Rights Reserved                */
/************************************************************************/
/*
  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License (GNU LGPL) as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  To obtain a copy of the GNU LGPL, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
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

    #if defined(_BOARD_FUBARINO_SD_) || defined(_BOARD_FUBARINO_MINI_)
    // the 3 second delay is put in for the Furbario USB to allow time to open the serial monitor
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
