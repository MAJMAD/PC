#include <stdio.h>
#include <string.h>
int main(void){
  int num = 0;
  printf("Enter an integer\n");
  scanf("%d", &num);
  char pic[num][num];
  for (int j = 0; j < num; j++){
    for (int q = 0; q < num; q++){
      if ((j == 0) || (j == num-1)){
        pic[j][q] = 'X';
      }
      else if ((q == 0) || (q == num-1)){
        pic[j][q] = 'X';
      }
      else {
        pic[j][q] = 'O';
      }
    }
  }
  for (int r = 0; r < num; r++){
  printf("%c",pic[0][r]);
}
  for (int e = 1; e < num; e++){
    printf("\n");
    for (int r = 0; r < num; r++){
    printf("%c",pic[e][r]);
  }
}
  return 0;
}
