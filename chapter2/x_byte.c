#include <stdio.h>
#include <assert.h>

typedef unsigned packed_t;


/**
 * Extract byte from word, return as signed integer
 * 
 * eg:  x_byte(0x00112233, 0) == 0x33
 *      x_byte(0xAABBCCDD, 0) == 0xFFFFFFDD
*/

int x_byte(packed_t x, int bytenum){
  int max_bytenum = 3;
  return (int) x << ((max_bytenum - bytenum) << 3) >> (max_bytenum << 3);
}

int main(int argc, char * argv[]){
  assert(x_byte(0x00112233, 0) == 0x33);
  assert(x_byte(0x00112233, 1) == 0x22);
  assert(x_byte(0x00112233, 2) == 0x11);
  assert(x_byte(0x00112233, 3) == 0x00);

  assert(x_byte(0xAABBCCDD, 0) == 0xFFFFFFDD);
  assert(x_byte(0xAABBCCDD, 1) == 0xFFFFFFCC);
  assert(x_byte(0xAABBCCDD, 2) == 0xFFFFFFBB);
  assert(x_byte(0xAABBCC77, 2) == 0x77);
  assert(x_byte(0xAABBCCDD, 3) == 0xFFFFFFAA);
  return 0;
}