#include <stdio.h>
#include <assert.h>

/**
 * Generate mask indicating leftmost 1 in x. Assume w=32
 * For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000
 * If x = 0, then return 0
 * 
 * solution:
 *  1. get the mask that all bits after leftmost on are ones.
 *  2. mask >> 1 + (mask && 1)
*/
int leftmost_one(unsigned x){
  // 1
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;

  // 2
  return (x >> 1) + (x && 1);
}

int main(int argc, char * argv[]){
  assert(leftmost_one(0xFF00) == 0x8000);
  assert(leftmost_one(0x6000) == 0x4000);
  assert(leftmost_one(0x0) == 0x0);
  assert(leftmost_one(0x80000000) == 0x80000000);
  return 0;
}