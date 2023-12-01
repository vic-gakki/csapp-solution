#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <limits.h>

int divide_power2(int x, int k){
  int mask = x & INT_MIN;
  mask && (x = x + (1 << k) - 1);
  return x >> k;
}

/**
 * can cause overflow
*/
int mul3div4(int x){
  x = (x << 1) + x;
  return divide_power2(x, 2);
}

/**
 * Compute the value of 3/4x, rounded toward zero.
 * It should not overflow
 *  - means need to do divide first and then multiply
 *  - x = a + b = a / 4 * 3 + b * 3 / 4
*/
int three_fourths(int x){
  int mask = x & INT_MIN;
  int a = x & ~0x3;
  int b = x & 0x3;
  int ad4 = a >> 2;
  int ad4m3 = (ad4 << 1) + ad4;

  int bm3 = (b << 1) + b;
  int bias = (1 << 2) - 1;
  mask && (bm3 = bm3 + bias);
  int bm3d4 = bm3 >> 2;
  return ad4m3 + bm3d4;
}

int main(int argc, char * argv[]){
  assert(three_fourths(8) == 6);
  assert(three_fourths(9) == 6);
  assert(three_fourths(10) == 7);
  assert(three_fourths(11) == 8);
  assert(three_fourths(12) == 9);

  assert(three_fourths(-8) == -6);
  assert(three_fourths(-9) == -6);
  assert(three_fourths(-10) == -7);
  assert(three_fourths(-11) == -8);
  assert(three_fourths(-12) == -9);
  return 0;
}
