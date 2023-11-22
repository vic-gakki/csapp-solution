#include <stdio.h>
#include <assert.h>

/**
 * return 1 when x can be represented as an n-bit, two's-complement number; 0 otherwise;
 * assume 1 <= n <= w
 * 
 * can only be represented when left bits prior to n is all 0s or 1s
*/
int fit_bits(int x, int n){
  int left_remain = x >> (n - 1) >> 1;
  int leftmost_n_bit = 1 << (n - 1) & x;
  int mask = !leftmost_n_bit - 1;
  // printf("mask is %.2x\n, test is %2.x\n", mask, ((1 << (n - 1)) & x));
  return left_remain == mask;
}


int fit_bits2(int x, int n){
  int w = sizeof(int) << 3;
  int offset = w - n;
  return (x << offset >> offset) == x;
}

int main(int argc, char * argv[]){
  assert(!fit_bits(0xFF, 8));
  assert(!fit_bits(~0xFF, 8));

  assert(fit_bits(0b0010, 3));
  assert(!fit_bits(0b1010, 3));
  assert(!fit_bits(0b0110, 3));

  assert(fit_bits(~0b11, 3));
  assert(!fit_bits(~0b01000011, 3));
  assert(!fit_bits(~0b111, 3));

  assert(!fit_bits2(0xFF, 8));
  assert(!fit_bits2(~0xFF, 8));

  assert(fit_bits2(0b0010, 3));
  assert(!fit_bits2(0b1010, 3));
  assert(!fit_bits2(0b0110, 3));

  assert(fit_bits2(~0b11, 3));
  assert(!fit_bits2(~0b01000011, 3));
  assert(!fit_bits2(~0b111, 3));
  return 0;
}


/**
 * x:
 * 0000 0000 0000 0000 0000 0000 1111 1111
 * 
 * 
 * 
 * 
 * 
 * 
*/

