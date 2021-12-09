//Jacob Mader 1/28/18
//Purpose: To calculate and return the volume and value of any amount of money.
#include <stdio.h>
int main(void){
  int temp = 0;
  int bills = 0;
  int billsVal = 0;
  double billsVol = 0;
  int change = 0;
  int changeVal = 0;
  double changeVol = 0;

  printf("Enter the number of $20s you have: ");
  scanf("%d", &temp);
  bills += temp;
  billsVal += temp*20;
  printf("\nEnter the number of $10s you have: ");
  scanf("%d", &temp);
  bills += temp;
  billsVal += temp*10;
  printf("\nEnter the number of $5s you have: ");
  scanf("%d", &temp);
  bills += temp;
  billsVal += temp*5;
  printf("\nEnter the number of $1s you have: ");
  scanf("%d", &temp);
  bills += temp;
  billsVal += temp;
  printf("\nEnter the number of quarters you have: ");
  scanf("%d", &temp);
  changeVal += temp*25;
  changeVol += 1.213*1.213*3.14159*0.175*(double)temp;
  printf("\nEnter the number of dimes you have: ");
  scanf("%d", &temp);
  changeVal += temp*10;
  changeVol += 0.8955*0.8955*3.14159*0.135*(double)temp;
  printf("\nEnter the number of nickels you have: ");
  scanf("%d", &temp);
  changeVal += temp*5;
  changeVol += 1.0605*1.0605*3.14159*0.195*(double)temp;
  printf("\nEnter the number of pennies you have: ");
  scanf("%d", &temp);
  changeVal += temp;
  changeVol += 0.9525*0.9525*3.14159*0.152*(double)temp;

  billsVol = 2.61*6.14*0.0043*2.54*2.54*2.54*(double)bills;

  printf("\nYou have %d in bills and %d cents in change.", billsVal, changeVal);
  printf("\nThe volume of your bills is %lf cubic centimeters.",billsVol);
  printf("\nThe volume of your change is %lf cubic centimeters.", changeVol);

  return 0;
}
