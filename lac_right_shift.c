#include <stdio.h>
#include <assert.h>
// implement logical right shift using arithmetic right shift and vice versa.


// implement logical right shift
unsigned srl(unsigned x, int k){
  unsigned xsra = (int) x >> k;
  // ~0                                         -> 11111111 11111111 11111111 11111111
  // ~0 << (sizeof(int) * 8 - 1 - k when k = 3  -> 11100000 00000000 00000000 00000000
  // ~(~0 << (sizeof(int) * 8 - 1 - k))         -> 00011111 11111111 11111111 11111111
  return (~(~0 << (sizeof(int) << 3 - k)) & xsra);
}


int sra(int x, int k){
  int xsrl = (unsigned) x >> k;
  int w = sizeof(int) << 3;
  unsigned mask = ~0 << (w - k);
  unsigned first_bit_checker = 1 << w - 1;
  unsigned first_bit_mask = !(x & first_bit_checker) - 1;
  mask &= first_bit_mask;
  return xsrl | mask;
}


int main(void){
  // unsigned test_unsigned = 0x92345678;
  // int test_int = 0x92345678;
  // printf("%d, %u", test_int, test_unsigned);

  unsigned test_unsigned = 0x12345678;
  int test_int = 0x12345678;

  assert(srl(test_unsigned, 4) == test_unsigned >> 4);
  assert(sra(test_int, 4) == test_int >> 4);

  test_unsigned = 0x87654321;
  test_int = 0x87654321;

  assert(srl(test_unsigned, 4) == test_unsigned >> 4);
  assert(sra(test_int, 4) == test_int >> 4);

  return 0;
}