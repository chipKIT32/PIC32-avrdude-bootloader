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
#include "HexData.h"

#define addrBlk0  0x1FC02FF4
const unsigned char rgbBlk0[] = { 
    0xd9, 0x79, 0xf8, 0xff, 0x7b, 0x09, 0x6a, 0xff, 0xff, 0xff, 0xff, 0x7f };
#define cbBlk0  12

#define addrBlk1  0x1FC00000
const unsigned char rgbBlk1[] = { 
    0xc0, 0xbf, 0x1a, 0x3c, 0x10, 0x00, 0x5a, 0x27, 0x08, 0x00, 0x40, 0x03, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0xa0, 0x1d, 0x3c, 0xf8, 0x1f, 0xbd, 0x27, 0x01, 0xa0, 0x1c, 0x3c, 0xf0, 0x85, 0x9c, 0x27, 
    0x02, 0x60, 0x09, 0x40, 0x20, 0x58, 0x20, 0x01, 0x80, 0x1e, 0x2a, 0x7d, 0x84, 0x49, 0x49, 0x7d, 
    0x02, 0x60, 0x89, 0x40, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xdc, 0x41, 0x02, 0x60, 0x8b, 0x40, 
    0x00, 0xa0, 0x08, 0x3c, 0x20, 0x06, 0x08, 0x25, 0x00, 0xa0, 0x09, 0x3c, 0x60, 0x06, 0x29, 0x25, 
    0x06, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xad, 0x04, 0x00, 0x00, 0xad, 
    0x08, 0x00, 0x00, 0xad, 0x0c, 0x00, 0x00, 0xad, 0x10, 0x00, 0x08, 0x25, 0x2b, 0x08, 0x09, 0x01, 
    0xf9, 0xff, 0x20, 0x14, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x9f, 0x08, 0x3c, 0x14, 0x0d, 0x08, 0x25, 
    0x00, 0x00, 0x09, 0x8d, 0x18, 0x00, 0x20, 0x11, 0x04, 0x00, 0x08, 0x25, 0x00, 0x00, 0x0a, 0x8d, 
    0x04, 0x00, 0x08, 0x25, 0x00, 0x00, 0x0b, 0x8d, 0x09, 0x00, 0x60, 0x11, 0x04, 0x00, 0x08, 0x25, 
    0x00, 0x00, 0x0c, 0x91, 0xff, 0xff, 0x4a, 0x25, 0x01, 0x00, 0x08, 0x25, 0x00, 0x00, 0x2c, 0xa1, 
    0xfb, 0xff, 0x40, 0x15, 0x01, 0x00, 0x29, 0x25, 0x05, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x20, 0xa1, 0xff, 0xff, 0x4a, 0x25, 0xfd, 0xff, 0x40, 0x15, 0x01, 0x00, 0x29, 0x25, 
    0x03, 0x00, 0x08, 0x25, 0xfc, 0xff, 0x0a, 0x24, 0x24, 0x40, 0x48, 0x01, 0x00, 0x00, 0x09, 0x8d, 
    0xe7, 0xff, 0x20, 0x15, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xbf, 0x09, 0x3c, 0x00, 0x00, 0x29, 0x25, 
    0x01, 0x78, 0x89, 0x40, 0x00, 0x00, 0x84, 0x30, 0x00, 0x00, 0xa5, 0x30, 0xc0, 0x9f, 0x08, 0x3c, 
    0x5c, 0x0d, 0x08, 0x25, 0x08, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00 };
#define cbBlk1  268

#define addrBlk2  0x1FC00498
const unsigned char rgbBlk2[] = { 
    0x00, 0x6a, 0x0b, 0x10, 0x07, 0xb3, 0x60, 0x9b, 0xff, 0x6e, 0x01, 0x4e, 0xcc, 0xeb, 0xfa, 0x23, 
    0x4d, 0xe4, 0xc0, 0xa3, 0x04, 0xb3, 0x01, 0x4a, 0xc0, 0xdb, 0xa2, 0xea, 0xf3, 0x61, 0xa0, 0xe8, 
    0x10, 0x60, 0x80, 0xbf, 0x20, 0x60, 0x80, 0xbf, 0x0e, 0xb5, 0xf0, 0xf0, 0x6c, 0x44, 0x44, 0x43, 
    0x43, 0xed, 0x00, 0x6a, 0x14, 0x61, 0x60, 0x9b, 0xc1, 0x43, 0x11, 0x26, 0x03, 0x6e, 0x6c, 0xee, 
    0x0e, 0x2e, 0xc7, 0x43, 0x39, 0x4e, 0xc3, 0xed, 0x0a, 0x61, 0x4f, 0xab, 0xae, 0xab, 0x40, 0x32, 
    0x40, 0x32, 0xad, 0xea, 0x8e, 0xea, 0x01, 0x5a, 0x58, 0x67, 0x4b, 0xea, 0x6c, 0xea, 0xa0, 0xe8, 
    0x00, 0x00, 0x08, 0x9d, 0xe3, 0x64, 0x30, 0xb2, 0x40, 0x9a, 0xff, 0x6b, 0x01, 0x4b, 0x6c, 0xea, 
    0x1c, 0x67, 0xf9, 0x22, 0x00, 0x6b, 0x2d, 0xb2, 0x60, 0xda, 0x00, 0xf4, 0x00, 0x6c, 0x2c, 0xb2, 
    0x01, 0xf0, 0x00, 0x4b, 0x80, 0xda, 0x60, 0xda, 0x2a, 0xb2, 0x80, 0xda, 0x10, 0xf0, 0x90, 0x98, 
    0x60, 0xda, 0x1f, 0x1a, 0x30, 0x01, 0x00, 0x65, 0x42, 0x22, 0x70, 0xf0, 0x61, 0xa0, 0x11, 0xeb, 
    0x0d, 0x23, 0x6b, 0xaa, 0x8a, 0xaa, 0x60, 0x33, 0x60, 0x33, 0x8d, 0xeb, 0x22, 0xb4, 0x8c, 0xeb, 
    0x05, 0x23, 0x22, 0xb4, 0x1f, 0x1a, 0x30, 0x01, 0x00, 0x65, 0x07, 0x22, 0x6d, 0xaa, 0x8c, 0xaa, 
    0x60, 0x33, 0x60, 0x33, 0x8d, 0xeb, 0x10, 0xf0, 0x74, 0xd8, 0x61, 0xaa, 0x80, 0xaa, 0x60, 0x33, 
    0x60, 0x33, 0x8d, 0xeb, 0x3c, 0x5b, 0x23, 0x61, 0x7b, 0xaa, 0x9a, 0xaa, 0x60, 0x33, 0x60, 0x33, 
    0x8d, 0xeb, 0x90, 0x67, 0x10, 0xf0, 0x10, 0x4c, 0xac, 0x44, 0x63, 0xed, 0x18, 0x61, 0xbc, 0xaa, 
    0x5d, 0xaa, 0x40, 0x32, 0x40, 0x32, 0xad, 0xea, 0x09, 0x5a, 0x01, 0x61, 0x08, 0x6a, 0x73, 0xe4, 
    0x43, 0xec, 0x01, 0x60, 0x44, 0x67, 0x90, 0x67, 0x50, 0xf0, 0x48, 0xd8, 0x50, 0xf0, 0x08, 0x4c, 
    0x05, 0x10, 0xa0, 0xa4, 0xff, 0x4a, 0x01, 0x4c, 0xa0, 0xc3, 0x01, 0x4b, 0xfa, 0x2a, 0x10, 0xf0, 
    0x54, 0x98, 0xc0, 0xea, 0x10, 0x60, 0x80, 0xbf, 0x00, 0x60, 0x80, 0xbf, 0x64, 0x60, 0x88, 0xbf, 
    0x48, 0x60, 0x88, 0xbf, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x9d, 0x00, 0xe0, 0xa5, 0x7c, 
    0x81, 0xbf, 0x03, 0x3c, 0x88, 0xbf, 0x02, 0x3c, 0x00, 0x40, 0x42, 0x8c, 0x20, 0xf4, 0x65, 0xac, 
    0x81, 0xbf, 0x03, 0x3c, 0x30, 0xf4, 0x66, 0xac, 0x00, 0xe0, 0xc6, 0x7c, 0x81, 0xbf, 0x03, 0x3c, 
    0x40, 0xf4, 0x66, 0xac, 0x30, 0x00, 0x05, 0x24, 0x88, 0xbf, 0x03, 0x3c, 0x04, 0x40, 0x65, 0xac, 
    0x30, 0x00, 0x42, 0x30, 0x00, 0x80, 0x03, 0x40, 0xf8, 0xff, 0x05, 0x24, 0x24, 0x28, 0x65, 0x00, 
    0x02, 0x00, 0xa5, 0x34, 0x00, 0x80, 0x85, 0x40, 0x81, 0xbf, 0x05, 0x3c, 0x00, 0x40, 0x84, 0x34, 
    0x00, 0xf4, 0xa4, 0xac, 0x00, 0x48, 0x04, 0x40, 0x00, 0x48, 0x06, 0x40, 0x23, 0x30, 0xc4, 0x00, 
    0xf0, 0x00, 0xc6, 0x2c, 0xfc, 0xff, 0xc0, 0x14, 0x99, 0xaa, 0x06, 0x3c, 0x81, 0xbf, 0x04, 0x3c, 
    0x55, 0x66, 0xc6, 0x24, 0x10, 0xf4, 0x86, 0xac, 0x66, 0x55, 0x06, 0x3c, 0xaa, 0x99, 0xc6, 0x34, 
    0x10, 0xf4, 0x86, 0xac, 0x00, 0x80, 0x06, 0x34, 0x81, 0xbf, 0x04, 0x3c, 0x08, 0xf4, 0x86, 0xac, 
    0x00, 0xf4, 0xa4, 0x8c, 0x00, 0x80, 0x84, 0x30, 0xfd, 0xff, 0x80, 0x14, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x48, 0x04, 0x40, 0x00, 0x48, 0x05, 0x40, 0x23, 0x28, 0xa4, 0x00, 0x14, 0x00, 0xa5, 0x2c, 
    0xfc, 0xff, 0xa0, 0x14, 0x00, 0x40, 0x05, 0x24, 0x81, 0xbf, 0x04, 0x3c, 0x04, 0xf4, 0x85, 0xac, 
    0x00, 0x80, 0x83, 0x40, 0x88, 0xbf, 0x03, 0x3c, 0x08, 0x00, 0xe0, 0x03, 0x08, 0x40, 0x62, 0xac, 
    0x01, 0x6a, 0xf5, 0x64, 0x4b, 0xea, 0x04, 0x67, 0x05, 0x69, 0x11, 0x10, 0xa0, 0x9b, 0x04, 0x4b, 
    0xac, 0xea, 0x8a, 0xeb, 0xfb, 0x61, 0x61, 0x42, 0x0e, 0x23, 0x08, 0xf0, 0x04, 0x6c, 0xb0, 0x67, 
    0x00, 0x6e, 0xff, 0x49, 0x1f, 0x1e, 0x75, 0x01, 0x04, 0xd2, 0x04, 0x92, 0x04, 0x21, 0x02, 0xf0, 
    0x80, 0x40, 0x70, 0x67, 0xee, 0x17, 0x75, 0x64, 0xa0, 0xe8, 0x00, 0x65, 0xf5, 0x64, 0x02, 0xf0, 
    0x00, 0x6a, 0x11, 0xb1, 0x4b, 0xea, 0x04, 0x67, 0x4c, 0xe8, 0xff, 0x4d, 0x25, 0xe0, 0x4c, 0xed, 
    0x22, 0x31, 0x02, 0xf0, 0x00, 0x4d, 0x32, 0x31, 0x10, 0x10, 0x0c, 0xb2, 0x49, 0xe1, 0x60, 0xa2, 
    0x09, 0x2b, 0x90, 0x67, 0x05, 0xd2, 0x1f, 0x1a, 0xaa, 0x01, 0x04, 0xd5, 0x05, 0x92, 0x01, 0x6b, 
    0x60, 0xc2, 0x04, 0x95, 0x01, 0x49, 0x02, 0xf0, 0x00, 0x48, 0xa3, 0xe8, 0xee, 0x61, 0x75, 0x64, 
    0xa0, 0xe8, 0x00, 0x65, 0x00, 0x00, 0x00, 0x63, 0x60, 0x0e, 0x00, 0xa0, 0xf5, 0x64, 0x66, 0x67, 
    0x04, 0x67, 0x25, 0x67, 0x00, 0x6a, 0x0f, 0x10, 0xc0, 0x99, 0x81, 0x46, 0x09, 0x24, 0x08, 0xf0, 
    0x01, 0x6c, 0xb0, 0x67, 0x04, 0xd2, 0x1f, 0x1e, 0x75, 0x01, 0x05, 0xd3, 0x05, 0x93, 0x04, 0x92, 
    0x04, 0x48, 0x01, 0x4a, 0x04, 0x49, 0x63, 0xea, 0xef, 0x61, 0x75, 0x64, 0xa0, 0xe8, 0x00, 0x65, 
    0xf4, 0x64, 0x3c, 0x67, 0x10, 0xf0, 0x90, 0x99, 0x1f, 0x1a, 0x30, 0x01, 0x00, 0x65, 0x02, 0x67, 
    0x3c, 0x22, 0xb1, 0x67, 0x84, 0x42, 0x30, 0xf0, 0x00, 0x4d, 0x1f, 0x1a, 0xcd, 0x01, 0x01, 0x6e, 
    0x87, 0x40, 0xb1, 0x67, 0x09, 0x4c, 0x30, 0xf0, 0x04, 0x4d, 0x1f, 0x1a, 0xcd, 0x01, 0x01, 0x6e, 
    0x87, 0x40, 0xb1, 0x67, 0x05, 0x4c, 0x30, 0xf0, 0x08, 0x4d, 0x1f, 0x1a, 0xcd, 0x01, 0x01, 0x6e, 
    0x87, 0x40, 0xb1, 0x67, 0x35, 0x4c, 0x30, 0xf0, 0x0c, 0x4d, 0x1f, 0x1a, 0xcd, 0x01, 0x01, 0x6e, 
    0x4b, 0xa8, 0x6a, 0xa8, 0x40, 0x32, 0x40, 0x32, 0x6d, 0xea, 0x11, 0xb3, 0x4c, 0xeb, 0x1c, 0x2b, 
    0x10, 0xb3, 0x4c, 0xeb, 0x0c, 0x23, 0x8f, 0xa8, 0x4e, 0xa8, 0xb1, 0xa8, 0x80, 0x34, 0x80, 0x34, 
    0x4d, 0xec, 0x50, 0xa8, 0xa0, 0x35, 0xa0, 0x35, 0x4d, 0xed, 0x95, 0xe5, 0x0a, 0x10, 0x0a, 0xb3, 
    0x0a, 0xb4, 0x6c, 0xea, 0x05, 0x22, 0x0a, 0xb5, 0x04, 0x10, 0x0a, 0xb5, 0x07, 0xb4, 0x01, 0x10, 
    0x08, 0xb5, 0x1f, 0x1a, 0xb9, 0x01, 0x00, 0x65, 0x74, 0x64, 0xa0, 0xe8, 0x00, 0x00, 0x02, 0x00, 
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x9d, 0x00, 0x00, 0x08, 0x9d, 
    0x00, 0xf0, 0x07, 0x9d, 0xfd, 0x64, 0x1c, 0x67, 0x70, 0xf0, 0x44, 0x98, 0xa7, 0xb3, 0x82, 0xa3, 
    0xa7, 0xb5, 0x59, 0xe5, 0x80, 0xc6, 0xc1, 0x42, 0xd9, 0xe5, 0x00, 0x6f, 0xe0, 0xc6, 0x06, 0x74, 
    0xc2, 0x42, 0x70, 0xf0, 0xc4, 0xd8, 0x76, 0x60, 0x07, 0x5c, 0x08, 0x60, 0x02, 0x74, 0x30, 0x60, 
    0x03, 0x74, 0x34, 0x60, 0x01, 0x6b, 0x6e, 0xec, 0x10, 0x24, 0xfd, 0x10, 0x13, 0x74, 0x7a, 0x60, 
    0x14, 0x5c, 0x04, 0x60, 0x11, 0x74, 0xe0, 0xf0, 0x0c, 0x60, 0xf5, 0x10, 0x14, 0x74, 0xa0, 0xf0, 
    0x16, 0x60, 0x1d, 0x6f, 0xee, 0xec, 0x2a, 0x24, 0xee, 0x10, 0x01, 0x6b, 0xd9, 0xe5, 0x03, 0x4a, 
    0x70, 0xf0, 0x60, 0xc0, 0x08, 0x6b, 0x60, 0xc6, 0x50, 0xf0, 0x90, 0xc0, 0x70, 0xf0, 0x88, 0xc0, 
    0x70, 0xf0, 0x44, 0xd8, 0xb5, 0xe2, 0x8f, 0xb3, 0x80, 0x83, 0x01, 0x4b, 0x80, 0xc5, 0x01, 0x4d, 
    0xfb, 0x2c, 0x08, 0x4a, 0x70, 0xf0, 0x44, 0xd8, 0x01, 0xf0, 0x00, 0x6b, 0x8a, 0xb2, 0xd2, 0x10, 
    0x43, 0xa3, 0x64, 0xa3, 0x89, 0xb4, 0x49, 0xe4, 0x60, 0xc2, 0xcd, 0x10, 0x63, 0xa3, 0x87, 0xb4, 
    0xd5, 0xe5, 0x6d, 0xe4, 0x60, 0xa3, 0x03, 0x4a, 0x60, 0xc5, 0x31, 0x10, 0xe6, 0xa3, 0xd9, 0xe5, 
    0x80, 0xc6, 0x59, 0xe5, 0xe3, 0xc6, 0x84, 0xc6, 0x30, 0x77, 0xc5, 0x42, 0x70, 0xf0, 0xc4, 0xd8, 
    0x0d, 0x61, 0x68, 0xa3, 0xd5, 0xe5, 0x03, 0x2b, 0x50, 0x6b, 0x60, 0xc5, 0x16, 0x10, 0x01, 0x73, 
    0x06, 0x4a, 0x49, 0x6b, 0x01, 0x60, 0x43, 0x6b, 0x60, 0xc5, 0x10, 0x10, 0x20, 0x77, 0x02, 0x60, 
    0x28, 0x77, 0x09, 0x61, 0x72, 0xb2, 0x01, 0x6b, 0xc9, 0xe2, 0x6b, 0xeb, 0x01, 0x4e, 0x60, 0xc2, 
    0x70, 0xf0, 0xc4, 0xd8, 0x05, 0x10, 0xd5, 0xe5, 0x80, 0xc5, 0x06, 0x4a, 0x70, 0xf0, 0x44, 0xd8, 
    0x70, 0xf0, 0x44, 0x98, 0x6a, 0xb3, 0x00, 0x6c, 0x4d, 0xe3, 0x80, 0xc3, 0x01, 0x4a, 0x70, 0xf0, 
    0x44, 0xd8, 0x91, 0x10, 0x84, 0xa3, 0x43, 0xa3, 0x80, 0x34, 0x80, 0x34, 0x00, 0xf6, 0x40, 0x32, 
    0x8d, 0xea, 0x86, 0xa3, 0x65, 0xa3, 0x8d, 0xea, 0x60, 0x33, 0x6d, 0xea, 0x44, 0x32, 0x10, 0xf0, 
    0x78, 0x98, 0x41, 0x10, 0x43, 0xa3, 0x64, 0xa3, 0x40, 0x32, 0x6d, 0xea, 0x04, 0x6b, 0x6b, 0xeb, 
    0x23, 0x42, 0x6c, 0xe9, 0x62, 0x67, 0x06, 0x10, 0x5d, 0xb4, 0x01, 0x6d, 0x91, 0xe3, 0xab, 0xed, 
    0xa0, 0xc4, 0x01, 0x4b, 0x23, 0xeb, 0xf8, 0x61, 0x10, 0xf0, 0x7c, 0xa0, 0x1c, 0x23, 0x00, 0xf1, 
    0x00, 0x59, 0x16, 0x61, 0x70, 0xf0, 0x8c, 0x98, 0xe0, 0xf1, 0x1f, 0x6b, 0x8c, 0xeb, 0x10, 0x2b, 
    0x54, 0xb3, 0x60, 0x9b, 0xa1, 0x43, 0x0c, 0x25, 0x10, 0xf0, 0xb8, 0x98, 0x10, 0xf0, 0x70, 0xd8, 
    0xb7, 0xe4, 0x51, 0xb4, 0x6c, 0xec, 0x10, 0xf0, 0x98, 0xd8, 0x91, 0xe5, 0x70, 0xf0, 0x8c, 0xd8, 
    0x00, 0x6b, 0x10, 0xf0, 0x7c, 0xc0, 0x70, 0xf0, 0xac, 0x98, 0x14, 0xd2, 0x85, 0x67, 0x1f, 0x1a, 
    0xb9, 0x01, 0xb5, 0xe1, 0x70, 0xf0, 0x8c, 0x98, 0x45, 0xb5, 0x1f, 0x1a, 0xcd, 0x01, 0x2a, 0x36, 
    0x70, 0xf0, 0x6c, 0x98, 0x14, 0x92, 0x49, 0xe3, 0x70, 0xf0, 0x4c, 0xd8, 0x3c, 0x10, 0x83, 0xa3, 
    0x70, 0xf0, 0x4c, 0x98, 0x64, 0xa3, 0x80, 0x34, 0x51, 0xe4, 0x6d, 0xec, 0x1e, 0x10, 0x3f, 0xb7, 
    0x02, 0xf0, 0x00, 0x6d, 0xab, 0xed, 0x4c, 0xed, 0x02, 0xf0, 0x60, 0x45, 0xf5, 0xe5, 0xa2, 0x35, 
    0xb2, 0x35, 0x3b, 0xb7, 0xb5, 0xe7, 0xa0, 0xa5, 0x01, 0x75, 0xff, 0x6d, 0x01, 0x61, 0x00, 0x6d, 
    0x63, 0xec, 0x09, 0x60, 0x64, 0x67, 0x07, 0x10, 0xe0, 0xa2, 0x2d, 0xb1, 0x25, 0xe6, 0xad, 0xef, 
    0xe0, 0xc1, 0x01, 0x4e, 0x01, 0x4a, 0x63, 0xea, 0xf7, 0x61, 0x83, 0xea, 0xe0, 0x61, 0x70, 0xf0, 
    0x4c, 0xd8, 0x27, 0xb2, 0xc9, 0xe2, 0x00, 0x6b, 0x01, 0x4e, 0x60, 0xc2, 0x70, 0xf0, 0xc4, 0xd8, 
    0x0a, 0x10, 0x1f, 0x1a, 0xda, 0x01, 0x00, 0x65, 0x01, 0x6a, 0x70, 0xf0, 0x41, 0xc0, 0x01, 0xf0, 
    0x00, 0x6b, 0x28, 0xb2, 0x60, 0xda, 0x70, 0xf0, 0x24, 0x98, 0x1b, 0x6a, 0x7d, 0x67, 0x50, 0xc3, 
    0x30, 0xf0, 0x78, 0xa0, 0x9d, 0x67, 0x23, 0x32, 0x71, 0xc4, 0x52, 0xc4, 0x33, 0xc4, 0xfd, 0x67, 
    0x0e, 0x6c, 0x94, 0xc7, 0x1b, 0x6c, 0x8e, 0xeb, 0x6e, 0xea, 0x0e, 0x6d, 0x2e, 0xea, 0xae, 0xea, 
    0x04, 0x04, 0x30, 0xf0, 0x50, 0xc0, 0x1f, 0x1a, 0x26, 0x01, 0x05, 0x6d, 0x30, 0xf0, 0x90, 0xa0, 
    0x00, 0x6b, 0x05, 0x10, 0x0e, 0xb2, 0x49, 0xe3, 0x40, 0xa2, 0x01, 0x4b, 0x4e, 0xec, 0x43, 0x67, 
    0x2e, 0xea, 0xf8, 0x2a, 0x30, 0xf0, 0x90, 0xc0, 0xb1, 0x67, 0x09, 0xb4, 0x1f, 0x1a, 0x26, 0x01, 
    0x14, 0xd2, 0x90, 0x67, 0x30, 0xf0, 0x10, 0x4c, 0x1f, 0x1a, 0x26, 0x01, 0x01, 0x6d, 0x14, 0x92, 
    0x70, 0xf0, 0x44, 0xd8, 0x7d, 0x64, 0xa0, 0xe8, 0x60, 0x06, 0x00, 0xa0, 0x60, 0x0a, 0x00, 0xa0, 
    0x6c, 0x0d, 0xc0, 0x9f, 0x68, 0x60, 0x88, 0xbf, 0xe0, 0x0e, 0x00, 0xa0, 0x6c, 0x06, 0x00, 0xa0, 
    0x64, 0x07, 0x00, 0xa0, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x63, 0x60, 0x0e, 0x00, 0xa0, 
    0x64, 0x60, 0x88, 0xbf, 0x5c, 0x67, 0x30, 0xf0, 0x70, 0xa2, 0x30, 0xf0, 0xb4, 0x9a, 0x11, 0xec, 
    0x8e, 0xeb, 0x07, 0x5d, 0x30, 0xf0, 0x70, 0xc2, 0x45, 0x60, 0x04, 0x0e, 0xa4, 0x35, 0xb5, 0xe6, 
    0xa0, 0x8d, 0xd9, 0xe5, 0x80, 0xee, 0x00, 0x65, 0x0f, 0x00, 0x1f, 0x00, 0x27, 0x00, 0x31, 0x00, 
    0x3f, 0x00, 0x4f, 0x00, 0x6f, 0x00, 0x1b, 0x74, 0x03, 0x61, 0x01, 0x6b, 0x30, 0xf0, 0x74, 0xda, 
    0x30, 0xf0, 0x90, 0xc2, 0xa0, 0xe8, 0x30, 0xf0, 0x98, 0xc2, 0x02, 0x6b, 0x21, 0x10, 0x80, 0x34, 
    0x30, 0xf0, 0x9c, 0xda, 0x03, 0x6b, 0x1c, 0x10, 0x30, 0xf0, 0x7c, 0x9a, 0x8d, 0xeb, 0x30, 0xf0, 
    0x7c, 0xda, 0x04, 0x6b, 0x15, 0x10, 0x0e, 0x6b, 0x6e, 0xec, 0x00, 0x6b, 0x11, 0x2c, 0x50, 0xf0, 
    0x80, 0xda, 0x05, 0x6b, 0x0d, 0x10, 0x50, 0xf0, 0x60, 0x9a, 0x0c, 0xb5, 0x75, 0xe5, 0x82, 0xc5, 
    0x30, 0xf0, 0x9c, 0x9a, 0x01, 0x4b, 0x50, 0xf0, 0x60, 0xda, 0x8e, 0xeb, 0x0b, 0x2b, 0x06, 0x6b, 
    0x30, 0xf0, 0x74, 0xda, 0xa0, 0xe8, 0x03, 0x2b, 0x01, 0x6b, 0x50, 0xf0, 0x64, 0xc2, 0x00, 0x6b, 
    0x30, 0xf0, 0x74, 0xda, 0xa0, 0xe8, 0x00, 0x65, 0x60, 0x06, 0x00, 0xa0, 0x4f, 0xb2, 0x60, 0x9a, 
    0xe3, 0x64, 0x1c, 0x67, 0x50, 0x67, 0x50, 0xf0, 0x08, 0x4a, 0x61, 0xda, 0xff, 0xf7, 0x1f, 0x6b, 
    0x4b, 0xb2, 0x60, 0xda, 0x02, 0x6b, 0x4b, 0xb2, 0x60, 0xda, 0x4b, 0xb3, 0x00, 0xf4, 0x00, 0x6a, 
    0x40, 0xdb, 0x49, 0xe2, 0x40, 0xdb, 0x49, 0xb3, 0x40, 0xdb, 0x49, 0xb2, 0x01, 0x6b, 0x02, 0xf0, 
    0x40, 0x9a, 0x4f, 0xea, 0x01, 0x5a, 0x58, 0x67, 0x6e, 0xea, 0x46, 0xb3, 0x80, 0x9b, 0x02, 0xf0, 
    0x00, 0x6b, 0x6c, 0xec, 0x01, 0x6b, 0x0d, 0x24, 0x43, 0xb4, 0xa0, 0x9c, 0x6c, 0xed, 0x09, 0x2d, 
    0xa0, 0x9c, 0x80, 0x6e, 0xcc, 0xed, 0x05, 0x2d, 0x60, 0x9c, 0x40, 0x6c, 0x8c, 0xeb, 0x01, 0x5b, 
    0x78, 0x67, 0x6c, 0xea, 0x50, 0xf0, 0x50, 0xc0, 0x02, 0xf0, 0x00, 0x6b, 0x3b, 0xb2, 0x60, 0xda, 
    0x00, 0x6b, 0x32, 0xb2, 0x60, 0xda, 0x1f, 0x1e, 0x05, 0x03, 0x00, 0x65, 0x00, 0x48, 0x02, 0x40, 
    0x08, 0x03, 0xf0, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x65, 0x10, 0xf0, 0x00, 0x6b, 0x50, 0xf0, 
    0x54, 0xd8, 0x50, 0xf0, 0x58, 0xd8, 0x32, 0xb2, 0x60, 0xda, 0x12, 0xf4, 0x00, 0x4b, 0x31, 0xb2, 
    0x60, 0xda, 0x2a, 0x6b, 0x30, 0xb2, 0x60, 0xda, 0x02, 0x10, 0x30, 0xb2, 0x40, 0x9a, 0x30, 0xb2, 
    0x40, 0x9a, 0x01, 0x6b, 0x6c, 0xea, 0xf9, 0x2a, 0x1f, 0x1e, 0x16, 0x03, 0x00, 0x65, 0x00, 0x65, 
    0x00, 0x48, 0x02, 0x40, 0x19, 0x03, 0xf0, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x65, 0x29, 0xb3, 
    0x70, 0xf0, 0xa0, 0xa0, 0x50, 0xf0, 0x98, 0x98, 0x50, 0xf0, 0x5c, 0xd8, 0x66, 0xed, 0x93, 0xe2, 
    0x63, 0xec, 0x06, 0x61, 0x00, 0xf4, 0x00, 0x6c, 0x23, 0xb3, 0x80, 0xdb, 0x50, 0xf0, 0x58, 0xd8, 
    0x70, 0xf0, 0x61, 0xa0, 0x11, 0xeb, 0x09, 0x2b, 0x50, 0xf0, 0x70, 0xa0, 0x09, 0x23, 0x50, 0xf0, 
    0x74, 0x98, 0x6b, 0xe2, 0x1d, 0xb3, 0x43, 0xeb, 0x03, 0x60, 0x1f, 0x1a, 0x3f, 0x01, 0x00, 0x65, 
    0x17, 0xb2, 0x40, 0x9a, 0x01, 0x6b, 0x6c, 0xea, 0x05, 0x22, 0x14, 0xb2, 0x80, 0x9a, 0x1f, 0x1a, 
    0xbb, 0x02, 0x11, 0xec, 0x50, 0xf0, 0x44, 0xa0, 0xc7, 0x22, 0x1f, 0x1a, 0x07, 0x02, 0x00, 0x65, 
    0x00, 0x6a, 0x50, 0xf0, 0x44, 0xc0, 0xc0, 0x17, 0x00, 0xf6, 0x80, 0xbf, 0x60, 0x90, 0x80, 0xbf, 
    0x00, 0x40, 0x88, 0xbf, 0x44, 0x60, 0x88, 0xbf, 0x64, 0x60, 0x88, 0xbf, 0x00, 0x00, 0x00, 0x9d, 
    0xa0, 0x60, 0x88, 0xbf, 0x00, 0xf6, 0x80, 0xbf, 0xa4, 0x60, 0x88, 0xbf, 0x00, 0x60, 0x80, 0xbf, 
    0x10, 0x60, 0x80, 0xbf, 0x40, 0x60, 0x80, 0xbf, 0x30, 0x60, 0x80, 0xbf, 0x10, 0x60, 0x80, 0xbf, 
    0x40, 0x4b, 0x4c, 0x00, 0x6c, 0x60, 0x88, 0xbf, 0xff, 0xb3, 0xc4, 0x04, 0x60, 0x06, 0x00, 0xa0, 
    0x80, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x06, 0x00, 0xa0, 0x40, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0xa0, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x9d, 0x00, 0x10, 0x00, 0x9d, 0x00, 0x00, 0x00, 0x9d, 0x01, 0x00, 0x00, 0x00, 
    0x08, 0x01, 0x00, 0x01, 0x01, 0x00, 0x04, 0x02, 0x31, 0x05, 0x0f, 0x13, 0x00, 0x06, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xe5, 0x02, 0xf0, 0x77, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x10, 
    0x00, 0x00, 0x00, 0x00, 0x53, 0x54, 0x4b, 0x35, 0x30, 0x30, 0x5f, 0x32, 0x00, 0x00, 0x00, 0x65 };
#define cbBlk2  2272

BLT rgBLT[] = { 
    { addrBlk0, cbBlk0, rgbBlk0 },
    { addrBlk1, cbBlk1, rgbBlk1 },
    { addrBlk2, cbBlk2, rgbBlk2 } };
const unsigned long cBLT = 3;

const char szUpdBd[]                =  "Cerebot MX4cK";

const unsigned long addrConfigBits  =  0xBFC02FF4;
const unsigned long cbConfigBits    =  0xC;

const unsigned long bootloaderVer   =  0x01000108;
const unsigned short vendID         =  0x0001;
const unsigned short productID      =  0x0204;
