#include <stdio.h>
int main(void){
  double wage = 0;
  int hours = 0;
  double income = 0;

  printf("Enter your hourly wage and number of hours worked \n");
  scanf("%lf %d", &wage, &hours);

  if (hours <= 40){
    income = wage * hours;
  }
  else if (hours <= 50){
    income = (wage * 40) + (wage * 1.5 *(hours - 40));
  }
  else {
    income = (wage * 40) + (wage * 1.5 * 10) + (wage * 2 * (hours - 50));
  }
  printf("Entering %lf and %d give a pay of %lf", wage, hours, income);
  return 0;
}
