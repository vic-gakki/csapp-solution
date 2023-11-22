#include <stdio.h>
#include <assert.h>
#include <limits.h>

/**
 * Addition that saturates to TMin or TMax
*/
int saturating_add(int x, int y){
  int w = sizeof(int) << 3;
  int sum = x + y;
  int lmx = ((unsigned) x) >> (w - 1);
  int lmy = (unsigned) y >> (w - 1);
  int lmm = (unsigned) sum >> (w - 1);
  int pos_flow_flag = !lmx && !lmy && lmm;
  int neg_flow_flag = lmx && lmy && !lmm;
  pos_flow_flag && (sum = INT_MAX) || neg_flow_flag && (sum = INT_MIN);
  return sum;
}

int saturating_add2(int x, int y){
  int sum = x + y;
  int mask = INT_MIN;
  int pos_flag = !(x & mask) && !(y & mask) && (sum & mask);
  int neg_flag = (x & mask) && (y & mask) && !(sum & mask);
  pos_flag && (sum = INT_MAX) || neg_flag && (sum = INT_MIN);
  return sum;
}


int main(int argc, char * argv[]){
  assert(saturating_add(0x80000000, 0x80000000) == INT_MIN);
  assert(saturating_add(0x10, 0x20) == 0x30);
  assert(saturating_add(0x7FFFFFFF, 0x7FFFFFFF) == INT_MAX);

  assert(saturating_add2(0x80000000, 0x80000000) == INT_MIN);
  assert(saturating_add2(0x10, 0x20) == 0x30);
  assert(saturating_add2(0x7FFFFFFF, 0x7FFFFFFF) == INT_MAX);
  return 0;
}
