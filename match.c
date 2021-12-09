#include <stdio.h>
#include <string.h>
int main(void){
  char word1[25];
  char word2[25];
  char word3[25];
  char word4[25];
  printf("Enter four words\n");
  scanf("%s %s %s %s", word1, word2, word3, word4);
  if((strcmp(word1, word2 )==0)||(strcmp(word1, word3 )==0)||
  (strcmp(word1, word4 )==0)||(strcmp(word2, word3 )==0)||(strcmp(word2, word4 )==0)||(strcmp(word3, word4 )==0)){
    printf("Match");
  }
  else {printf("No Match");}
  return 0;
}
