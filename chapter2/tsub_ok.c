#include <stdio.h>
#include <assert.h>
#include <limits.h>

/**
 *  Determine whether arguments can be subtracted without overflow
 *  This function should return 1 if the computation x-y does not overflow
*/
int tsub_ok(int x, int y){
  int sum = x - y;
  int mask = INT_MIN;
  int pos_flag = !(x & mask) && (y & mask) && (sum & mask);
  int neg_flag = (x & mask) && !(y & mask) && !(sum & mask);
  return !(pos_flag || neg_flag);
}

int main(int argc, char * argv[]){
    assert(!tsub_ok(INT_MIN, 1));
    assert(!tsub_ok(INT_MAX, -1));
    assert(tsub_ok(0, 0));
    assert(!tsub_ok(INT_MIN, INT_MAX));
    assert(!tsub_ok(INT_MAX, INT_MIN));
    assert(tsub_ok(10, 8));
  return 0;
}