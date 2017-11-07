#ifndef BitLib_h
#define BitLib_h

#include <Arduino.h>

class BitLib {
public:
    BitLib();
    ~BitLib();

    bool getBit(unsigned char number, unsigned char index);
};
#endif
