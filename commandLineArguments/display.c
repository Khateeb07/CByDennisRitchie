#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  if(argc == 1){
    printf("No arguments passed\n");
    return 0;
  }
  int i=1;
  while(argv[i]!=NULL){
    printf("%s\n", argv[i]);
    i++;
  }
  return 0;
}
