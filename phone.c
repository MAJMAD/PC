#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phone.h"

///////////////////////////////////////////////////////////////

void printNumber(long val) {
	return;
}

///////////////////////////////////////////////////////////////

MultiLinkedList *add(MultiLinkedList *list, char *first, char *last, long num) {
	Node *newNode = malloc ( sizeof(Node) );
	newNode->first = malloc ( strlen(first) + 1 );
	strcpy(newNode->first, first);
	newNode->last = malloc ( strlen(last) + 1 );
	strcpy(newNode->last, last);
	newNode->number = num;
	// add this new node at the head of the "byFirst" list
	newNode->nextFirst = list->headFirstName;
	list->headFirstName = newNode;
	// add this new node at the head of the "byLast" list
	newNode->nextLast = list->headLastName;
	list->headLastName = newNode;
	// return the multi-list object with updated head pointers
	return list;
}

int size(MultiLinkedList *list) {//works
  int count = 0;
  Node *nod = malloc( sizeof(Node) );
  nod = list->headFirstName;
  while (nod) {
          count++;
          nod = nod->nextFirst;
  }
  return count;
}

void printByFirst(MultiLinkedList *list) {//works
	Node *nod = malloc( sizeof(Node) );
  nod = list->headFirstName;
	long num1 = list->headFirstName->number/10000000;
	long num2 = (list->headFirstName->number/10000)%1000;
	long num3 = list->headFirstName->number%10000;
	printf("%s %s %ld-%ld-%ld\n", nod->first, nod->last, num1, num2, num3);
	nod = nod->nextFirst;
	while(nod){
		num1 = nod->number/10000000;
		num2 = (nod->number/10000)%1000;
		num3 = nod->number%10000;
		printf("%s %s %ld-%ld-%ld\n", nod->first, nod->last, num1, num2, num3);
		nod = nod->nextFirst;
	}
	return;
}

void printByLast(MultiLinkedList *list) {//works
	Node *nod = malloc( sizeof(Node) );
  nod = list->headLastName;
	long num1 = list->headLastName->number/10000000;
	long num2 = (list->headLastName->number/10000)%1000;
	long num3 = list->headLastName->number%10000;
	printf("%s %s %ld-%ld-%ld\n", nod->first, nod->last, num1, num2, num3);
	nod = nod->nextLast;
	while(nod){
		num1 = nod->number/10000000;
		num2 = (nod->number/10000)%1000;
		num3 = nod->number%10000;
		printf("%s %s %ld-%ld-%ld\n", nod->first, nod->last, num1, num2, num3);
		nod = nod->nextLast;
}
return;
}

int lookup(MultiLinkedList *list, char *name) {//works
  Node *nod = malloc( sizeof(Node) );
  nod = list->headFirstName;
	int count = 0;
	long num1 = list->headLastName->number/10000000;
	long num2 = (list->headLastName->number/10000)%1000;
	long num3 = list->headLastName->number%10000;
	while(nod){
		num1 = nod->number/10000000;
		num2 = (nod->number/10000)%1000;
		num3 = nod->number%10000;
    if(strcasecmp(name, nod->first) == 0 || strcasecmp(name, nod->last) == 0 ){
			count++;
			printf("%s %s %ld-%ld-%ld\n", nod->first, nod->last, num1, num2, num3);
		}
	nod = nod->nextFirst;
}
return count;
}

void updatePhone(MultiLinkedList *list, char *first, char *last, long number) {//works
	Node *nod = malloc( sizeof(Node) );
	nod = list->headLastName;
	int x = 0;
	while(nod){
    if(strcasecmp(first, nod->first) == 0 && strcasecmp(last, nod->last) == 0 ){
			nod->number = number;
			x++;
		}
	nod = nod->nextFirst;
}
if (x == 0){
	printf("Error, name does not exist.");
}
	return;
}

MultiLinkedList *removeItem(MultiLinkedList *list, char *first, char *last) {//works
	Node *nod = malloc( sizeof(Node) );
	nod = list->headLastName;
	int x = 0;
	while(nod->nextFirst){
    if(strcasecmp(first, nod->nextFirst->first) == 0 && strcasecmp(last, nod->nextFirst->last) == 0 ){
			nod->nextFirst = nod->nextFirst->nextFirst;
			nod->nextLast = nod->nextLast->nextLast;
			x++;
		}
	nod = nod->nextFirst;
}
if (x == 0){
	printf("Error, name does not exist.");
}
	return list;
}

MultiLinkedList *updateFirst(MultiLinkedList *list, char *first, char *last, char *newFirst) {
	Node *nod = malloc( sizeof(Node) );
	nod = list->headFirstName;
	int x = 0;
	while(nod){
    if(strcasecmp(newFirst, nod->first) == 0 && strcasecmp(last, nod->last) == 0 ){
			printf("Error, name already exists.");
			x++;
			return list;
		}
	nod = nod->nextFirst;
}
	while(nod){
    if(strcasecmp(first, nod->first) == 0 && strcasecmp(last, nod->last) == 0 ){
			nod->first = newFirst;
			x++;
		}
	nod = nod->nextFirst;
}
if (x == 0){
	printf("Error, name does not exist.");
}
	return list;
}

MultiLinkedList *updateLast(MultiLinkedList *list, char *first, char *last, char *newLast) {
	Node *nod = malloc( sizeof(Node) );
	nod = list->headLastName;
	int x = 0;
	while(nod){
    if(strcasecmp(first, nod->first) == 0 && strcasecmp(newLast, nod->last) == 0 ){
			printf("Error, name already exists.");
			x++;
			return list;
		}
	nod = nod->nextLast;
}
nod = list->headLastName;
	while(nod){
    if(strcasecmp(first, nod->first) == 0 && strcasecmp(last, nod->last) == 0 ){
			nod->last = newLast;
			x++;
		}
	nod = nod->nextLast;
}
if (x == 0){
	printf("Error, name does not exist.");
}
	return list;
}
