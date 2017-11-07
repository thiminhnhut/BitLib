#include <BitLib.h>

BitLib::BitLib() {

}
BitLib::~BitLib() {

}

bool BitLib::getBit(unsigned char number, unsigned char index) {
    return (number >> index) & 0x01;
}
