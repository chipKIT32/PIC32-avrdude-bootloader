typedef struct
{
    unsigned long   addr;
    unsigned long   cb;
    unsigned char * rgb;
} BLT;      // Block LisT

// can't be const because we sort it and change the ranges
extern BLT rgBLT[];
extern const unsigned long cBLT;

// The must be exactly _BOARD_NAME_ as specfied in Borad_Defs.h
extern const char szUpdBd[]; 
extern const unsigned long bootloaderVer;
extern const unsigned short vendID;
extern const unsigned short productID;

extern const unsigned long addrConfigBits;
extern const unsigned long cbConfigBits;