#include "BitLib.h"

BitLib::BitLib() {}

unsigned char BitLib::maxSizeBitsChar(unsigned char nobit) {
  unsigned char maxSize = 0;
  for (unsigned char i = 0; i < nobit; i++) {
    maxSize += (1 << i);
  }
  return maxSize;
}
unsigned int BitLib::maxSizeBitsInt(unsigned char nobit) {
  unsigned int maxSize = 0;
  for (unsigned char i = 0; i < nobit; i++) {
    maxSize += (1 << i);
  }
  return maxSize;
}
