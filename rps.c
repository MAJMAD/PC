#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getNumGames (void){
  int games = 0;
  printf("Enter how many games you would like to play\n");
  scanf("%d", &games);
  return games;
}
int findWinner( int p1move, int p2move){
  if ( ((p1move == 0) && (p2move == 1)) || ((p1move == 1) && (p2move == 2)) || ((p1move == 2) && (p2move == 0))){
    return 2;
  }
  else if ( ((p2move == 0) && (p1move == 1)) || ((p2move == 1) && (p1move == 2)) || ((p2move == 2) && (p1move == 0))){
    return 1;
  }
  else if ( ((p2move == 0) && (p1move == 0)) || ((p2move == 1) && (p1move == 1)) || ((p2move == 2) && (p1move == 2))){
    return 0;
  }
  return -1;
}
void printResults(int ties, int p1wins, int p2wins ){
  printf("There were %d ties, %d player one wins, and %d player two wins", ties, p1wins, p2wins);
}
int main(void){
    srand(0);
    int games = 0;
    int p1move = 0;
    int p2move = 0;
    int ans = 0;
    int ties = 0;
    int p1wins = 0;
    int p2wins = 0;
    games = getNumGames();
    for (int a = 0; a < games; a++){
      p1move = rand() % 3;
      p2move = rand() % 3;
      ans = findWinner(p1move, p2move);
      if (ans == 0) ties++;
      if (ans == 1) p1wins++;
      if (ans == 2) p2wins++;
  }
  printResults(ties, p1wins, p2wins);
return 0;
}
