#include <stdio.h>
int compose(int x, int y){
  return (y & ~0xff) | (x & 0xff);
}

int main(void){
  printf("%.2x", compose(0x89ABCDEF, 0x76543210));
}