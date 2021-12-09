#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person {
	char *name;
	struct person *next;
} Person;

void print(Person *);
Person *add(Person *, char *);
int size(Person *);
int chars(Person *);

int main(void) {
	char input[100];
	Person *myList = NULL;
	printf("Enter a person's name (one word) : ");
	scanf("%s", input);
	while (strcasecmp (input, "xxx") != 0) {
		myList = add (myList, input);
		printf("Enter a name (one word), enter 'xxx' to exit : ");
		scanf("%s", input);
	}
	printf("\n\nThe final list is ");  print(myList);
	printf("\n\nIt has %d names that contain %d total characters\n",
		size(myList), chars(myList) );
	return 0;
}

void print(Person *ptr) {
	if (ptr == NULL) return;
	printf("%s ", ptr->name);
	print(ptr->next);
	return;
}

Person *add(Person *ptr, char *n) {
	Person *temp = ptr;
	while (temp) {
		if (strcasecmp(temp->name, n) == 0) {
			printf("Error - name %s already exists\n", n);
			return ptr;
		}
		temp = temp->next;
	}
	Person *newNode = malloc( sizeof(Person) );
	newNode->name = malloc( strlen(n) + 1 );
	strcpy(newNode->name, n);
	newNode->next = NULL;
	if (ptr == NULL)
		return newNode;
	if (strcasecmp(n, ptr->name) < 0) {
		newNode->next = ptr;
		return newNode;
	}
	Person *prev = ptr;
	Person *curr = ptr->next;
	while (curr && strcasecmp(curr->name, n) < 0) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = newNode;
	newNode->next = curr;
	return ptr;
}

int size(Person *name){
	if(name == NULL) return 0;

	else size(name->next);

	return 1 + size(name->next);
	return 0;
}

int chars(Person *name){
	if(name == NULL) return 0;

	else return strlen(name->name) + chars(name->next);
	return 0;
}
