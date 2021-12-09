#include <stdio.h>
#include <stdlib.h>

int sevens(int num) {
  static int count = 0;
  if(num > 0) {
    int temp = num %10;
    if(temp == 7) {
      ++count;
    }
    sevens(num/10);
  }
  return count;
}

int main(int argc, char *argv[]) {
    int val = atoi(argv[1]);
    printf("%d contains %d sevens\n", val, sevens(val) );
    return 0;
}
