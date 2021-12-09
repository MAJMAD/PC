#include <stdio.h>
#include <stdlib.h>
int main(void){
  int randoma[9];
  int ramount = 0;
  int rnumber = 0;
  int unique = 0;
  srand(0);
  printf("How many random values to generate: ");
  scanf("%d", &ramount);
  for (int j = 0; j <= 9; j++){
    randoma[j] = 0;
  }
  for (int j = 0; j < ramount; j++){
    rnumber = rand() % 10;
    for (int q = 0; q < 10; q++){
      if( rnumber == q ){
        randoma[q]++;
      }
    }
  }
  for (int j = 0; j <= 9; j++){
    if(randoma[j] != 0){
      unique++;
    }
  }
  printf("%d random numbers generated %d out of 10 possible values", ramount, unique);
return 0;
}
