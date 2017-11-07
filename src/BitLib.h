#ifndef BitLib_h
#define BitLib_h

#include <Arduino.h>

class BitLib {
public:
    BitLib();
    ~BitLib();

    bool getBit(unsigned char number, unsigned char index);
    unsigned char getBit2DecChar(unsigned char number, unsigned char index, unsigned char nobit);
    unsigned char getBit2DecChar(unsigned int number, unsigned char index, unsigned char nobit);
    unsigned int getBit2DecInt(unsigned int number, unsigned char index, unsigned char nobit);
};
#endif
