#include <stdio.h>
int main(void){
  int number = 0;
  int sum = 0;
  int temp = 0;
  int onumber = 0;
  printf("Enter a integer: \n");
  scanf("%d", &number);
  onumber = number;
  while (number != 0){
    sum += (number % 10);
    number = (number / 10);
  }
  printf("If the user enters %d, the program generates the answer %d", onumber, sum);
  return 0;
}
