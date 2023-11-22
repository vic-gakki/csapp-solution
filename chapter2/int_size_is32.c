#include <stdio.h>
#include <assert.h>

int int_size_is32(){
  int msb = 1 << 31;
  int beyond_msb = msb << 1;
  return msb && !beyond_msb;
}

int int_size_is32_for16bit(){
  int msb = 1 << 15 << 15 << 1;
  int beyond_msb = msb << 1;
  return msb && !beyond_msb;
}

int main(int argc, char * argv[]){
  assert(int_size_is32());
  assert(int_size_is32_for16bit());
  return 0;
}