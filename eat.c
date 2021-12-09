//Jacob Mader 1/30/18
//Purpose: Answer the question "Do you still want to eat what fell on the floor?"
#include <stdio.h>
#include <string.h>
int main(void){
  char response[25];
  int temp = 0;
  printf("What Fell on the Floor?\n");
  scanf("%s", response);


  if(strcmp(response, "meat")==0){
    temp = 1;
  }
  else if(strcmp(response, "produce")==0){
    temp = 2;
  }
  else if(strcmp(response, "bread")==0){
    temp = 3;
  }
  else if(strcmp(response, "junk-food")==0){
    temp = 4;
  }


  if ((temp == 1) || (temp == 4)){
    printf("What Kind?\n");
    scanf("%s", response);
  }
  else if (temp == 2){
    printf("Does it grow in the ground?\n");
    scanf("%s", response);
  }
  else if (temp == 3){
    printf("Buttered?\n");
    scanf("%s", response);
  }


  if(strcmp(response, "chicken")==0){
    temp = 1;
  }
  else if(strcmp(response, "beef")==0){
    temp = 2;
  }
  else if(strcmp(response, "other")==0){
    temp = 3;
  }
  else if(strcmp(response, "candy")==0){
    temp = 4;
  }
  else if(strcmp(response, "donuts")==0){
    temp = 5;
  }
  else if(strcmp(response, "chips")==0){
    temp = 6;
  }
  else if((strcmp(response, "yes")==0) && (temp == 2) ){
    temp = 7;
  }
  else if((strcmp(response, "no")==0) && (temp == 2) ){
    temp = 8;
  }
  else if((strcmp(response, "yes")==0) && (temp == 3) ){
    temp = 9;
  }
  else if((strcmp(response, "no")==0) && (temp == 3) ){
    temp = 10;
  }


  if (temp == 1){
    printf("Nuggets?\n");
    scanf("%s", response);
  }
  else if (temp == 2){
    printf("Steak?\n");
    scanf("%s", response);
  }
  else if (temp == 3){
    printf("Leftovers or fresh?\n");
    scanf("%s", response);
  }
  else if ((temp == 4)||(temp == 10)){
    printf("Is the floor clean?\n");
    scanf("%s", response);
  }
  else if (temp == 5){
    printf("Sprinkles?\n");
    scanf("%s", response);
  }
  else if (temp == 6){
    printf("Can you brush it off?\n");
    scanf("%s", response);
  }
  else if (temp == 7){
    printf("On floor for more than three seconds?\n");
    scanf("%s", response);
  }
  else if (temp == 8){
    printf("Smashed or Bruised?\n");
    scanf("%s", response);
  }
  else if (temp == 9){
    printf("Butter side up?\n");
    scanf("%s", response);
  }


  if((strcmp(response, "yes")==0) && (temp == 1) ){
    temp = 1;
  }
  else if((strcmp(response, "no")==0) && (temp == 1) ){
    temp = 2;
  }
  else if((strcmp(response, "yes")==0) && (temp == 2) ){
    temp = 99;
  }
  else if((strcmp(response, "no")==0) && (temp == 2) ){
    temp = 4;
  }
  else if(strcmp(response, "fresh")==0){
    temp = 5;
  }
  else if(strcmp(response, "leftovers")==0){
    temp = 6;
  }
  else if((strcmp(response, "yes")==0) && ((temp == 4) || (temp == 10))){
    temp = 99;
  }
  else if((strcmp(response, "no")==0) && ((temp == 4) || (temp == 10))){
    temp = -99;
  }
  else if((strcmp(response, "yes")==0) && (temp == 5) ){
    temp = 7;
  }
  else if((strcmp(response, "no")==0) && (temp == 5) ){
    temp = 8;
  }
  else if((strcmp(response, "yes")==0) && (temp == 6) ){
    temp = 9;
  }
  else if((strcmp(response, "no")==0) && (temp == 6) ){
    temp = -99;
  }
  else if((strcmp(response, "yes")==0) && (temp == 7) ){
    temp = -99;
  }
  else if((strcmp(response, "no")==0) && (temp == 7) ){
    temp = 99;
  }
  else if((strcmp(response, "yes")==0) && (temp == 8) ){
    temp = -99;
  }
  else if((strcmp(response, "no")==0) && (temp == 8) ){
    temp = 10;
  }
  else if((strcmp(response, "yes")==0) && (temp == 9) ){
    temp = 11;
  }
  else if((strcmp(response, "no")==0) && (temp == 9) ){
    temp = -99;
  }


  if ((temp == 1) || (temp == 6)||(temp == 8)||(temp == 9)){
    printf("On floor for more than three seconds??\n");
    scanf("%s", response);
  }
  else if ((temp == 2) || (temp == 4) || (temp == 7)||(temp == 10)||(temp == 11)){
    printf("Is the floor clean?\n");
    scanf("%s", response);
  }
  else if (temp == 5) {
    printf("Can you brush it off?\n");
    scanf("%s", response);
  }


  if((strcmp(response, "yes")==0) && ((temp == 1) || (temp == 6)||(temp == 8)||(temp == 9)) ){
    temp = -99;
  }
  else if((strcmp(response, "no")==0) && ((temp == 1) || (temp == 6)||(temp == 8)||(temp == 9)) ){
    temp = 99;
  }
  else if((strcmp(response, "yes")==0) && ((temp == 5)||(temp == 7)||(temp == 10)||(temp == 11)) ){
    temp = 99;
  }
  else if((strcmp(response, "no")==0) && ((temp == 2) || (temp == 4) || (temp == 5)||(temp == 11)) ){
    temp = -99;
  }
  else if((strcmp(response, "yes")==0) && ((temp == 2) || (temp == 4))){
    temp = 1;//on the floor
  }
  else if((strcmp(response, "no")==0) && (temp == 10) ){
    temp = 1;
  }
  else if((strcmp(response, "no")==0) && (temp == 7) ){
    temp = 2;//can you
  }


  if(temp == 1){
    printf("On floor for more than three seconds?\n");
    scanf("%s", response);
  }
  else if(temp == 2){
    printf("Can you brush it off?\n");
    scanf("%s", response);
  }


  if((strcmp(response, "yes")==0) && (temp == 1) ){
    temp = -99;
  }
  else if((strcmp(response, "no")==0) && (temp == 1) ){
    temp = 99;
  }
  else if((strcmp(response, "yes")==0) && (temp == 2) ){
    temp = 1;
  }
  else if((strcmp(response, "no")==0) && (temp == 2) ){
    temp = -99;
  }


  if(temp == 1){
    printf("On floor for more than three seconds?\n");
    scanf("%s", response);
  }
  if((strcmp(response, "yes")==0) && (temp == 1) ){
    temp = -99;
  }
  else if((strcmp(response, "no")==0) && (temp == 1) ){
    temp = 99;
  }


  if (temp == 99){
    printf("You can eat what you dropped.\n");
  }
  else if (temp == -99){
    printf("Do not eat what dropped.\n");
  }






return 0;
}
