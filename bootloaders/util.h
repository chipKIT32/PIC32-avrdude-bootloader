// *** util.h ******************************************************************

// N.B. the usb controller bdt data structures and the usb protocol
// layers are defined to be little endian.
//
// This file originated from the cpustick.com skeleton project from
// http://www.cpustick.com/downloads.htm and was originally written
// by Rich Testardi; please preserve this reference and share bug
// fixes with rich@testardi.com.

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