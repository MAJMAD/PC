#include <stdio.h>
#include <string.h>
#include <ctype.h>

void counts(char*, int*, int*, int*);

int main(int argc, char *argv[]){
  FILE *fp = fopen(argv[1],"r");
  char str[100];
  fscanf(fp, "%s", str);
  while (! feof(fp)){
    int upper = 0;
    int lower = 0;
    int digit = 0;
    counts(str, &upper, &lower, &digit);
    printf("%s has %d uppercase, %d lowercase, and %d digits\n",str, upper, lower, digit);
    fscanf(fp, "%s", str);
  }
  return 0;
}

void counts(char* str, int* up, int* down, int* num){
  int l = strlen(str);
  for (int a = 0; a < l; a++){
    if(str[a] > 64 && str[a] < 91){
      *up = *up + 1;
    }
    if(str[a] > 96 && str[a] < 123){
      *down = *down + 1;
    }
    if(str[a] > 47 && str[a] < 58){
      *num = *num + 1;
    }
}
}
