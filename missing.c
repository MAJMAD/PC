#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    int letters[26];
    char words[50];
    for (int j = 0; j <= 26; j++){
      letters[j] = 0;
    }
    printf("Enter your input: ");
    while(!feof(stdin)==1){
      fgets(words, 50, stdin);
    }
    for (int j = 0; j < 51; j++){
        for (int w = 97; w < 123; w++){
          if(words[j] == w){
            letters[w - 97]++;
        }
      }
    }
    printf("Missing letters: ");
    for (int j = 0; j <= 25; j++){
      if(letters[j] == 0){
        printf("%c ", j + 97);
      }
    }
return 0;
}
