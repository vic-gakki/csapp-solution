#include <stdio.h>
int main(int argc, char *argv[]){
  int counter = 0;
  for(; counter < argc; counter++){
    printf("%s\n", argv[counter]);
  }
  return 0;
}