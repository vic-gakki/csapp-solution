#include <stdio.h>

typedef unsigned char * byte_pointer;


int is_little_endian(void){
  short x = 0x00ff;
  byte_pointer px = (byte_pointer) &x;
  if(px[0] == 0xff){
    return 1;
  }
  return 0;
}

int is_little_endian2(void){
  int num = 1;
  return (short) num;
};

int main(void){
  printf("%d", is_little_endian());
}