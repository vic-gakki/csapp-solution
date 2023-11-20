#include <stdio.h>
#include <assert.h>

/**
 * Return 1 when x contains an odd number of 1s; 0 otherwise
 * 
 * 1101 -> 11 ^ 01 = 10 -> 1 ^ 0 = 1
 * 1010 -> 10 ^ 10 = 00 -> 0 ^ 0 = 0
 * 1001 -> 10 ^ 01 = 11 -> 1 ^ 1 = 0
*/
int odd_ones(unsigned x){
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  x &= 0x1;
  return x;
}

int main(int argc, char * argv[]){
  assert(odd_ones(0x10101011));
  assert(!odd_ones(0x01010101));
  return 0;
}