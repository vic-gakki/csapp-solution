#include <stdio.h>
int int_shifts_are_arithmetic(void){
  int x = ~0;
  return x >> 8 == ~0;
}

int int_shifts_are_arithmetic2(void){
  int x = -1;
  return !(x ^ (x >> 1));
}

int main(void){
  printf("%d\n", int_shifts_are_arithmetic());
  printf("%d\n", int_shifts_are_arithmetic2());
  return 0;
}