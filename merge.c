#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    FILE* data1 = NULL; // File pointer
    FILE* data2 = NULL;
    data1 = fopen("data1", "r");
    data2 = fopen("data2", "r");
    int d1 = 0;
    int d2 = 0;
    fscanf(data1,"%d", &d1);
    fscanf(data2,"%d", &d2);
    while(!feof(data1) && !feof(data2)){
        if( d1 < d2 ){
          printf("%d ",d1);
          fscanf(data1,"%d", &d1);
        }
        else if( d1 > d2 ){
          printf("%d ",d2);
          fscanf(data2,"%d", &d2);
        }
        else if( d1 == d2 ){
          printf("%d ",d1);
          fscanf(data1,"%d", &d1);
          fscanf(data2,"%d", &d2);
        }
    }
    while(!feof(data1)){
      printf("%d ",d1);
      fscanf(data1,"%d", &d1);
    }
    while(!feof(data2)){
      printf("%d ",d2);
      fscanf(data2,"%d", &d2);
    }
    fclose(data1);
    fclose(data2);
return 0;
}
