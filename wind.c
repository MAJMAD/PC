#include <stdio.h>
#include <math.h>
int main(void){
  int temp = 0;
  int speed = 0;
  double chill = 0;
  double dummy = 0;

  printf("Enter a temperature and a wind speed \n");
  scanf("%d %d", &temp, &speed);
  dummy = pow(speed, 0.16);
  chill = 35.74 + (0.6215 * (double)temp) - (35.75 * (double)dummy) + (0.4275 * temp * (double)dummy);
  printf("Entering %d and %d gives a wind chill of %lf", temp, speed, chill);
  return 0;
}
