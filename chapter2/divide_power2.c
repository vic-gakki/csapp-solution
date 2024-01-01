#include <stdio.h>
#include <assert.h>
#include <limits.h>
/**
 * Divide by power of 2, 0 <= k < w - 1
 * with correct rounding
*/
int divide_power2(int x, int k){
  int mask = x & INT_MIN;
  mask && (x = x + (1 << k) - 1);
  return x >> k;
}

int main(int argc, char * argv[]){
  int x = 0x80000007;
  printf("%d\n", -3 / 2);
  assert(divide_power2(x, 1) == x / 2);
  assert(divide_power2(x, 2) == x / 4);
  return 0;
}