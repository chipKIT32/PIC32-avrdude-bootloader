/**** util.h ******************************************************************
 *
 * N.B. the usb controller bdt data structures and the usb protocol
 * layers are defined to be little endian.
 *
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

// 3/1/2012 KeithV (Digilent) Updated to compiler inline and not conflict with
//                           exisiting prototypes; thus the il (InLine) in the name.
//                              Also designed to compile without plib.h, or stdlib.h included.
static inline void * __attribute__((always_inline)) ilmemcpy(void *d,  const void *s, unsigned int n)
{
    uint8 *dtemp = d;
    const uint8 *stemp = s;

    while (n--) {
        *(dtemp++) = *(stemp++);
    }
    return d;
}

static inline void * __attribute__((always_inline)) ilmemset(void *p,  int d, unsigned int n)
{
    uint8 *ptemp = p;

    while (n--) {
        *(ptemp++) = d;
    }
    return p;
}

static inline char * __attribute__((always_inline)) ilstrcpy(char *dest, const char *src)
{
    char *orig_dest = dest;

    do {
        *(dest++) = *src;
    } while (*(src++));

    return orig_dest;
}

static inline int __attribute__((always_inline)) ilsplx(int level)
{
    return 0;
}