#include <stdio.h>
#include <string.h>

void reverse(char*);

int main(int argc, char *argv[]){
  for (int a = 1; a < argc; a++){
    printf("%s becomes ", argv[a]);
    reverse(argv[a]);
    printf("%s\n", argv[a]);
  }
  return 0;
}

void reverse(char* argue){
  int L = strlen(argue);
  for (int a = 0; a < L/2; a++){
    char x = argue[a];
    argue[a] = argue[L-1-a];
    argue[L-1-a] = x;}
}
