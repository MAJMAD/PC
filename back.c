#include <stdio.h>
#include <string.h>
int main(void){
  char words[100][20];
  char bwords[100][20];
  int i = 0;
  printf("To end your list, enter control-d\n");
  printf("Enter a word\n");
  scanf("%s", words[0]);
  while (strcmp(words[i], "control-d" ) !=0){
    printf("Enter a word\n");
    scanf("%s", words[i+1]);
    i++;
  }
  for (int j = 0; j <= i; j++){
    for (int q = 0; q <= strlen(words[j]); q++){
      bwords[j][q] = words[j][strlen(words[j])-(1+q)];
    }
  }
  for (int l = 0; l <= i-1; l++){
    printf("%s\n", bwords[l]);
  }
  return 0;
}
