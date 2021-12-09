#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct person {
	char *name;
	int age;
	struct person *next;
} Person;
void print(Person *);			// prints the entire list
Person *add(Person *, char *, int);	// adds a new node to the list
int getAge(Person *, char *);		// returns the age of the person or -1 if not found

int main(void) {
	char input1[100];
	int input2;
	Person *myList = NULL;
	printf("Enter a person's name (one word) and age : ");
	scanf("%s %d", input1, &input2);
	while (input2 != 0) {
	       myList = add (myList, input1, input2);
              printf("\n\nThe list is now : ");  print(myList);
		printf("Enter a name (one word) and age, enter 'xxx' and 0 to exit : ");
		scanf("%s %d", input1, &input2);
	}
	printf("\n\nThe final list is ");  print(myList);
	printf("\n\nEnter the name of a person to look up their age : ");
	scanf("%s", input1);
	while ( strcmp(input1, "xxx") != 0 ) {
		printf("\t%s is %d years old\n", input1, getAge(myList, input1) );
		printf("Enter a name to look up their age or 'xxx' to exit : ");
		scanf("%s", input1);
	}
	return 0;
}
void print(Person *ptr) {
	while (ptr) { printf("[%s-%d] ", ptr->name, ptr->age); ptr = ptr->next; }
	printf("\n");
	return;
}
Person *add(Person *ptr, char *n, int a) {
	Person *newNode = malloc( sizeof(Person) );
	newNode->name = malloc( strlen(n) + 1 );
	strcpy(newNode->name, n);
	newNode->age = a;
	newNode->next = ptr;
	int size = 0;
	while (ptr){
		if (strcmp(newNode->name, ptr->name) == 0){
			printf("Sorry, this name is being used");
			return ptr;
		}
		else {
			ptr = ptr->next;
			size = size + 1;
		}
	}
	while (ptr){
		if (strcmp(newNode->name, ptr->name) < 0){
			newNode->next = ptr;
			return newNode;
		}
		else {
			newNode->next = ptr->next;
			ptr->next = newNode;
			return ptr;
		}
	}

return newNode;
}




int getAge(Person *ptr, char *n){
	while (ptr) {
		if (strcmp(ptr->name, n) == 0){
			return ptr->age;
		}
		ptr = ptr->next;
	}
		return -1;
}	// returns the age of the person or -1 if not found
