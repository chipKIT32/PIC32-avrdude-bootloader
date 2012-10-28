/************************************************************************/
/*                                                                      */
/*    serial.h   This is used to read and write to the serial UART      */
/*               speicifically for the stk500v2 avrdude/MPIDE PIC32     */
/*               compilient bootloader                                  */
/*                                                                      */
/************************************************************************/
/*    Author:     Keith Vogel                                           */
/*    Copyright 2012, Digilent Inc.                                     */
/************************************************************************/
/*
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/************************************************************************/
/*  Revision History:                                                   */
/*                                                                      */
/*  This is a re-write and combination of code originating from         */    
/*        (C) 2010, 2011 by Mark Sproul AND                             */
/*         Rich Testardi                                                */
/*                                                                      */
/*    2/23/2011(KeithV): ReWrite, to remove plib.h, make inline,        */
/*                       add PPS support,AND make configurable          */
/*                       by BoardConfig.h                               */
/************************************************************************/

static inline void __attribute__((always_inline)) serial_print(const byte *line, int length)
{
    int i;
 
    for (i = 0; i < length; i++) {
         while (!USTAbits.TRMT)
        {
            //*    wait for the buffer to be clear
        }
        UTXREG    =    line[i];
    }
}

static inline void __attribute__((always_inline)) serial_isr(void)
{
    // if the uart receiver is ready...
    if (USTAbits.URXDA)
    {
        // call the stk500v2 state machine with the input byte
        avrbl_state_machine(URXREG);
     }
}
