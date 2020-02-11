#include <Arduino.h>
#include <BitLib.h>

#define debug_port Serial
#define BAUDRATE 115200

BitLib bit;

/*** N = 0xFFFF = 0b1111111111111111
 *
 * 0b1(Enable) 1111(Chemical) 1111(Physical) 1111(Math) 111(ID)
 * ID[3bit, 0b111 = 7]: index bit[0 - 2]
 * Math[4bit, 0b1111 = 15]: index bit[3 - 6]
 * Physical[4bit, 0b1111 = 15]: index bit[7 - 10]
 * Chemical[4bit, 0b1111 = 15]: index bit[11 - 14]
 * Enable[1bit, 0b1 = 1]: index bit[15]
 */

void setup() {
  debug_port.begin(BAUDRATE);
  debug_port.println("-----------------------------------------------------");

  unsigned int N = 0xFFFF;                // '0b1111 1111 1111 1111'
  unsigned char count = bit.countBits(N); // 16
  debug_port.printf("Count Bit of %d: %d\n", N, count);

  // 0b 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
  debug(N, count);

  unsigned char id = 5;
  unsigned char math = 7;
  unsigned char physical = 9;
  unsigned char chemical = 10;
  unsigned char enable = 0;

  // 0b 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 -> 0b 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1
  N = bit.setBitsIndex(N, 0, 3, id);
  debug(N, count);

  // 0b 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 -> 0b 1 1 1 1 1 1 1 1 1 0 1 1 1 1 0 1
  N = bit.setBitsIndex(N, 3, 4, math);
  debug(N, count);

  // 0b 1 1 1 1 1 1 1 1 1 0 1 1 1 1 0 1 -> 0b 1 1 1 1 1 1 0 0 1 0 1 1 1 1 0 1
  N = bit.setBitsIndex(N, 7, 4, physical);
  debug(N, count);

  // 0b 1 1 1 1 1 1 0 0 1 0 1 1 1 1 0 1 -> 0b 1 1 0 1 0 1 0 0 1 0 1 1 1 1 0 1
  N = bit.setBitsIndex(N, 11, 4, chemical);
  debug(N, count);

  // 0b 1 1 0 1 0 1 0 0 1 0 1 1 1 1 0 1 -> 0b 0 1 0 1 0 1 0 0 1 0 1 1 1 1 0 1
  N = bit.setBitIndex(N, 15, enable);
  debug(N, count);

  id = bit.getBitsIndex2DecChar(N, 0, 3);
  math = bit.getBitsIndex2DecChar(N, 3, 4);
  physical = bit.getBitsIndex2DecChar(N, 7, 4);
  chemical = bit.getBitsIndex2DecChar(N, 11, 4);
  enable = bit.getBitsIndex2DecChar(N, 15, 1);
  debug_port.printf("ID:%d, Math:%d, Physical:%d, Chemical:%d, Enable:%d\n", id,
                    math, physical, chemical, enable);

  unsigned int value = bit.maxSizeBitsChar(4); // 0b1111 = 15
  debug_port.printf("value = %d\n", value);

  unsigned int value2 = bit.maxSizeBitsInt(16); // 0xFF = 65535
  debug_port.printf("value = %d\n", value2);
}

void loop() {}

void debug(unsigned int N, unsigned char count) {
  debug_port.printf("N=%d:\t", N);
  for (int i = count - 1; i >= 0; i--) {
    debug_port.printf("%d ", bit.getBitIndex(N, i));
  }
  debug_port.println("");
}