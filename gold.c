#include <stdio.h>
int main(void){
  int weight = 0;
  double temp = 0;


  printf("Enter your weight: ");
  scanf("%d", &weight);

  printf("\nEnter the price of gold: ");
  scanf("%lf", &temp);

  temp = temp*weight*16;

  printf("\nYou are worth $%lf", temp);

  return 0;
}
