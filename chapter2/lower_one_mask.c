#include <stdio.h>
#include <assert.h>

int lower_one_mask(int n){
  int onebigger = 1 << (n -1) << 1;
  return onebigger - 1;
}

int lower_one_mask2(int n){
  int w = sizeof(int) << 3;
  return (unsigned) -1 >> (w - n);
}


int main(int argc, char * argv[]){
  assert(lower_one_mask(6) == 0x3F);
  assert(lower_one_mask(17) == 0x1FFFF);
  assert(lower_one_mask(32) == 0xFFFFFFFF);

  assert(lower_one_mask2(6) == 0x3F);
  assert(lower_one_mask2(17) == 0x1FFFF);
  assert(lower_one_mask2(32) == 0xFFFFFFFF);
  return 0;
}