#include <stdio.h>

typedef unsigned char * byte_pointer;

unsigned replace_byte(unsigned x, int i, unsigned char b){
  byte_pointer px = (byte_pointer) &x;
  px[i] = b;
  return x;
}

unsigned replace_byte2(unsigned x, int i, unsigned char b) {
  if (i < 0) {
    printf("error: i is negetive\n");
    return x;
  }
  if (i > sizeof(unsigned)-1) {
    printf("error: too big i");
    return x;
  }

  // 1 byte has 8 bits, << 3 means * 8
  unsigned mask = ((unsigned) 0xFF) << (i << 3);
  unsigned pos_byte = ((unsigned) b) << (i << 3);

  return (x & ~mask) | pos_byte;
}




int main(void){
  printf("%.2x\n", replace_byte(0x12345678, 2, 0xab));
  printf("%.2x\n", replace_byte(0x12345678, 0, 0xab));
  printf("%.2x\n", replace_byte2(0x12345678, 2, 0xab));
  printf("%.2x\n", replace_byte2(0x12345678, 0, 0xab));
  printf("%d\n", !2);
  return 0;
}