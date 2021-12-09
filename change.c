#include <stdio.h>
int main(void){
  int quarters = 0;
  int dimes = 0;
  int nickels = 0;
  int pennies = 0;
  int value = 0;

  printf("Enter the number of quarters you have:");
  scanf("%d", &quarters);

  printf("\nEnter the number of dimes you have:");
  scanf("%d", &dimes);

  printf("\nEnter the number of nickels you have:");
  scanf("%d", &nickels);

  printf("\nEnter the number of pennies you have:");
  scanf("%d", &pennies);

  value = 25*quarters + 10*dimes + nickels*5 + pennies;

  printf("\nThe value of your change is %d cents", value);

  return 0;
}
