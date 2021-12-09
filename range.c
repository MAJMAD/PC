#include <stdio.h>
int main(void){
  int hVal = 0;
  int lVal = 0;
  int temp = 0;
  int range = 0;
  int p1 = 0;
  int p2 = 0;
  int p3 = 0;
  printf("Enter three integers: \n");
  scanf("%d %d %d", &hVal, &lVal, &range);
  p1 = hVal;
  p2 = lVal;
  p3 = range;
  if(hVal < lVal){
    temp = hVal;
    hVal = lVal;
    lVal = temp;
  }
  if(hVal < range){
    temp = hVal;
    hVal = range;
    range = temp;
  }
  if(lVal > hVal){
    temp = lVal;
    lVal = hVal;
    hVal = temp;
  }
  if(lVal > range){
    temp = lVal;
    lVal = range;
    range = temp;
  }
  range = (hVal - lVal);
  printf("Entering %d %d %d gives a range of %d", p1, p2, p3, range);
  return 0;
}
