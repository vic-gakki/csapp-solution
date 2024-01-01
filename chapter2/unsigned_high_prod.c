#include <stdio.h>
#include <assert.h>
#include <inttypes.h>
/**
 * let xw and yw be bit vectors of length w
 * define x and y as the values represented by these bits in two's complement form: x = B2T(xw), y = B2T(yw)
 * define x' and y' as the values represented by these bits in unsigned form: x' = B2U(xw), y = B2U(yw)
 * 
 * x' = x + leftmost_bit(xw) * Math.pow(2, w)
 * y' = y + leftmost_bit(yw) * Math.pow(2, w)
 * 
 * a = leftmost_bit(xw) * Math.pow(2, w)
 * b = leftmost_bit(yw) * Math.pow(2, w)
 * 
 * x' * y' = (x + a) * (y + b)
 *         = x * y + xb + ya + ab     // a * b can not be represeteb by 2w bits -> w = 4, amax = 16, bmax = 16, a * b = 256 = 1 0000 0000
 *         = x * y + xb + ya
 * 
 * x' * y' >> w = (x * y) >> w + x * leftmost_bit(yw) + y * leftmost_bit(xw)
*/

int int_high_prod(int x, int y){
   int64_t mul = (int64_t) x * y;
   return mul >> 32;
}

unsigned unsigned_high_prod_for_test(unsigned x, unsigned y){
  uint64_t mul = (uint64_t) x * y;
  return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y){
  int maskx = x >> 31;
  int masky = y >> 31;
  int signed_prod = int_high_prod(x, y);
  return signed_prod + maskx * y + masky * x;
}

int main(int argc, char * argv[]){
  unsigned x = 0x12345678;
  unsigned y = 0xFFFFFFFF;

  assert(unsigned_high_prod_for_test(x, y) == unsigned_high_prod(x, y));
  return 0;
}