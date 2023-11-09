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


int is_little_endian(void){
  int num = 1;
  return (short) num;
};

int is_little_endian2(void){
  short test_num = 0xff;
  byte_pointer p = (byte_pointer) &test_num;
  if(p[0] == 0xff){
    return 1;
  }
  return 0;
}

int is_big_endian(void){
  int num = 1;
  return (short) num == 0 ? 1 : 0;
};

int is_big_endian2(void){
  short test_num = 0xff;
  byte_pointer p = (byte_pointer) &test_num;
  if(p[1] == 0xff){
    return 1;
  }
  return 0;
}




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
  printf("%d\n", is_little_endian());
  printf("%d\n", is_little_endian2());
  printf("%d\n", is_big_endian());
  printf("%d\n", is_big_endian2());
}

int main(void){
  test_show_bytes(1);
}