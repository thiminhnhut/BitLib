#ifndef BitLib_h
#define BitLib_h

#include <Arduino.h>

class BitLib {
public:
  BitLib();

  template <typename T> bool getBitIndex(T number, unsigned char index);

  template <typename T>
  T getBitsIndex2DecInt(T number, unsigned char index, unsigned char nobit);

  template <typename T>
  unsigned char getBitsIndex2DecChar(T number, unsigned char index,
                                     unsigned char nobit);

  template <typename T> T setBitIndex(T number, unsigned char index, bool bit);

  template <typename T>
  void setBitIndex(T *number, unsigned char index, bool bit);

  template <typename T1, typename T2>
  T1 setBitsIndex(T1 number, unsigned char index, unsigned char nobit,
                  T2 number_replace);

  template <typename T1, typename T2>
  void setBitsIndex(T1 *number, unsigned char index, unsigned char nobit,
                    T2 number_replace);

  unsigned char maxSizeBitsChar(unsigned char nobit);
  unsigned int maxSizeBitsInt(unsigned char nobit);

  template <typename T> unsigned char countBits(T number);
};

template <typename T> bool BitLib::getBitIndex(T number, unsigned char index) {
  return (number >> index) & 0x01;
}

template <typename T>
unsigned char BitLib::getBitsIndex2DecChar(T number, unsigned char index,
                                           unsigned char nobit) {
  unsigned char value = 0;
  for (unsigned char i = 0; i < nobit; i++) {
    value += (number >> (index + i) & 0x01) * (1 << i);
  }
  return value;
}

template <typename T>
T BitLib::getBitsIndex2DecInt(T number, unsigned char index,
                              unsigned char nobit) {
  T value = 0;
  for (unsigned char i = 0; i < nobit; i++) {
    value += (number >> (index + i) & 0x01) * (1 << i);
  }
  return value;
}

template <typename T>
T BitLib::setBitIndex(T number, unsigned char index, bool bit) {
  return number ^ ((-bit ^ number) & (1 << index));
}

template <typename T>
void BitLib::setBitIndex(T *number, unsigned char index, bool bit) {
  *number = (*number) ^ ((-bit ^ (*number)) & (1 << index));
}

template <typename T1, typename T2>
T1 BitLib::setBitsIndex(T1 number, unsigned char index, unsigned char nobit,
                        T2 number_replace) {
  for (unsigned char i = 0; i < nobit; i++) {
    number = setBitIndex(number, index + i, 0);
  }
  return number | (number_replace << index);
}

template <typename T1, typename T2>
void BitLib::setBitsIndex(T1 *number, unsigned char index, unsigned char nobit,
                          T2 number_replace) {
  for (unsigned char i = 0; i < nobit; i++) {
    *number = setBitIndex(*number, index + i, 0);
  }
  *number = *number | (number_replace << index);
}

template <typename T> unsigned char BitLib::countBits(T number) {
  number = (number < 0) ? -number : number;
  unsigned char bits = 0;
  for (bits = 0; number != 0; ++bits) {
    number >>= 1;
  }
  return bits;
}
#endif
