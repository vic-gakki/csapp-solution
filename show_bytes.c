#include <stdio.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len){
  printf("%d\n", len);
  for(int i = 0; i < len; i++){
    printf("%.2x", start[i]);
  }
  printf("\n");
};

void show_short(short x){
  show_bytes((byte_pointer) &x, sizeof(short));
};

void show_int(int x){
  show_bytes((byte_pointer) &x, sizeof(int));
};

void show_float(float x){
  show_bytes((byte_pointer) &x, sizeof(float));
};

void show_double(double x){
  show_bytes((byte_pointer) &x, sizeof(double));
};

void show_pointer(void *x){
  show_bytes((byte_pointer) &x, sizeof(void *));
};

void test_show_bytes(int x){
  int ival = x;
  short sval = (short) x;
  float fval = (float) x;
  double dval = (double) x;
  int *pval = &ival;
  show_short(sval);
  show_int(ival);
  show_float(fval);
  show_double(dval);
  show_pointer(pval);
}

int main(void){
  test_show_bytes(1);
}