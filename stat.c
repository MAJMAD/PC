#include <stdio.h>
int main(void){
  int a = 0;
  int b = 0;
  int c = 0;
  double average = 0;

  printf("Enter your first number: ");
  scanf("%d", &a);
  printf("\nEnter your second number: ");
  scanf("%d", &b);
  printf("\nEnter your third number: ");
  scanf("%d", &c);

  average = ((double)(a + b + c))/3;

  printf("\nYour average is %lf", average);

  return 0;
}
