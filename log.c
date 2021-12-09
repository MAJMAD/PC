// Jacob Mader 2/28/18
// Purpose: This program reads data from input logs of texts messages and converts them into readable info for individuals.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char *readableTime(int sec);// provide function for converting epoch time to readable time
void date(char timestamp[], int timex); // replaces the new line character from readableTime output with a terminating character
void message(int x, FILE* y); // function that processes and formats message
void who(char number[], int x); // function that converts phone number to formatted form
int main(int argc, char* argv[]){
  FILE* data1 = NULL; // File pointer
  FILE* data2 = NULL;
  int time1 = 0;
  int time2 = 0;
  char cell1[11];
  char cell2[11];
  int wordc1 = 0;
  int wordc2 = 0;
  char timestamp[30];
  data1 = fopen(argv[1], "r");
  data2 = fopen(argv[2], "r");
  fscanf(data1, "%d", &time1);
  fscanf(data1, "%s", cell1);
  fscanf(data1, "%d", &wordc1);
  fscanf(data2, "%d", &time2);
  fscanf(data2, "%s", cell2);
  fscanf(data2, "%d", &wordc2);
  while(!feof(data1) && !feof(data2)){
    if( time1 < time2 ){
      date(timestamp, time1);
      who(cell1, 1);
      message(wordc1, data1);
      fscanf(data1, "%d", &time1);
      fscanf(data1, "%s", cell1);
      fscanf(data1, "%d", &wordc1);
    }
    else{
      date(timestamp, time2);
      who(cell2, 2);
      message(wordc2, data2);
      fscanf(data2, "%d", &time2);
      fscanf(data2, "%s", cell2);
      fscanf(data2, "%d", &wordc2);
    }
}
while(!feof(data1)){
  date(timestamp, time1);
  who(cell1, 1);
  message(wordc1, data1);
  fscanf(data1, "%d", &time1);
  fscanf(data1, "%s", cell1);
  fscanf(data1, "%d", &wordc1);
  }
  while(!feof(data2)){
    date(timestamp, time2);
    who(cell2, 2);
    message(wordc2, data2);
    fscanf(data2, "%d", &time2);
    fscanf(data2, "%s", cell2);
    fscanf(data2, "%d", &wordc2);
  }
return 0;
}

char *readableTime(int sec) { // provide function for converting epoch time to readable time
 time_t epoch_time = (time_t) sec;
 return asctime( localtime( &epoch_time ) );
}

void date(char timestamp[], int timex){
  strcpy(timestamp, readableTime(timex));
  for(int x = 0; x<26;x++){
    if(timestamp[x]=='\n'){
      timestamp[x] = '\0';
    }
  }
  printf("%s", timestamp);
}
void message(int x, FILE* y){
  char message[x][50];
  printf(" | ");
  for(int q = 0; q < x; q++){
    fscanf(y, "%s", message[q]);
    printf("%s ", message[q]);
  }
  printf("\n");
}

void who(char number[], int x){ // function that converts phone number to formatted form
  char who[5];
  if(x == 1){
    who[0] = 'F';
    who[1] = 'r';
    who[2] = 'o';
    who[3] = 'm';
    who[4] = '\0';
  }
  if(x == 2){
    who[0] = ' ';
    who[1] = ' ';
    who[2] = 'T';
    who[3] = 'o';
    who[4] = '\0';
  }
  printf(" %s ", who);
  for(int q = 0; q < 11; q++){
    if( (q == 3) || (q == 6)){
      printf("-");
    }
    printf("%c",number[q]);
  }
};
