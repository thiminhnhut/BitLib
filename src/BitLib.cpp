#include <BitLib.h>

BitLib::BitLib() {

}
BitLib::~BitLib() {

}

bool BitLib::getBit(unsigned char number, unsigned char index) {
    return (number >> index) & 0x01;
}

unsigned char BitLib::getBit2Dec(unsigned int number, unsigned char index, unsigned char nobit) {
    unsigned char value = 0;
    for (unsigned char i = 0; i < nobit; i++) {
        value += (number >> (index + i) & 0x01) * (1 << index + i);
    }
    return value;
}
