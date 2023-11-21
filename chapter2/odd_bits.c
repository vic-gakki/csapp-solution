#include <stdio.h>
#include <assert.h>

int any_odd_one(unsigned x){
  return !!(0xAAAAAAAA & x);
}

int main(int argc, char * argv[]){
  assert(any_odd_one(2));
  assert(any_odd_one(6));
  return 0;
}