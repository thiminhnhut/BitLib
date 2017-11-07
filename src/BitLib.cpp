#include <BitLib.h>

BitLib::BitLib() {

}
BitLib::~BitLib() {

}

bool BitLib::getBit(unsigned char number, unsigned char index) {
    return (number >> index) & 0x01;
}

unsigned char BitLib::getBit2DecChar(unsigned char number, unsigned char index, unsigned char nobit) {
    unsigned char value = 0;
    for (unsigned char i = 0; i < nobit; i++) {
        value += (number >> (index + i) & 0x01) * (1 << index + i);
    }
    return value;
}

unsigned char BitLib::getBit2DecChar(unsigned int number, unsigned char index, unsigned char nobit) {
    unsigned char value = 0;
    for (unsigned char i = 0; i < nobit; i++) {
        value += (number >> (index + i) & 0x01) * (1 << index + i);
    }
    return value;
}

unsigned int BitLib::getBit2DecInt(unsigned int number, unsigned char index, unsigned char nobit) {
    unsigned int value = 0;
    for (unsigned char i = 0; i < nobit; i++) {
        value += (number >> (index + i) & 0x01) * (1 << index + i);
    }
    return value;
}
