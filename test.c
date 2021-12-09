#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *readableTime(int sec);// provide function for converting epoch time to readable time
void fixtime(char timestamp[], int timex);
int main(int argc, char* argv[]){
  FILE* data1 = NULL; // File pointer
  int time1 = 0;
  char timestamp[25];
  data1 = fopen(argv[1], "r");
  fscanf(data1, "%d", &time1);
  fixtime(timestamp, time1);
  printf("%s test", timestamp);
return 0;
}

void fixtime(char timestamp[], int timex){
  strcpy(timestamp, readableTime(timex));
  for(int x = 0; x<26;x++){
    if(timestamp[x]=='\n'){
      timestamp[x] = '\0';
    }
  }

}



char *readableTime(int sec) { // provide function for converting epoch time to readable time
 time_t epoch_time = (time_t) sec;
 return asctime( localtime( &epoch_time ) );
}
