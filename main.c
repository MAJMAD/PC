#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phone.h"

int main(int argc, char *argv[]) {
	MultiLinkedList *theList;
	theList = malloc ( sizeof(MultiLinkedList) );

	theList->headFirstName = NULL;
	theList->headLastName = NULL;

	char str[20];
	char name1[100], name2[100], name3[100];
	long number;

	printf("Enter an option (add, size, printByFirst, printByLast\n\t\tlookup, updatePhone, removeItem\n\t\tupdateFirst, updateLast, quit) : ");
	scanf("%s", str);
	while ( strcasecmp(str, "quit") != 0 ) {
		if ( strcasecmp(str, "add") == 0 ) {
			printf("\tEnter first name : ");
			scanf("%s", name1);
			printf("\tEnter last name : ");
			scanf("%s", name2);
			printf("\tEnter phone number (10 digits, no dashes) : ");
			scanf("%ld", &number);
			theList = add(theList, name1, name2, number);
		}
		else if ( strcasecmp(str, "size") == 0 )
			printf("\nThe phone list has %d items\n\n", size(theList) );
		else if ( strcasecmp(str, "printByFirst") == 0 )
			printByFirst(theList);
		else if ( strcasecmp(str, "printByLast") == 0 )
			printByLast(theList);
		else if ( strcasecmp(str, "lookup") == 0 ) {
			printf("\tEnter name to search for : ");
			scanf("%s", name1);
			int matches = lookup(theList, name1);
			printf("\n\t%d matches\n", matches );
		}
		else if ( strcasecmp(str, "updatePhone") == 0 ) {
			printf("\tEnter first name : ");
			scanf("%s", name1);
			printf("\tEnter last name : ");
			scanf("%s", name2);
			printf("\tEnter new phone number (10 digits, no dashes) : ");
			scanf("%ld", &number);
			updatePhone(theList, name1, name2, number);
		}
		else if ( strcasecmp(str, "removeItem") == 0 ) {
			printf("\tEnter first name : ");
			scanf("%s", name1);
			printf("\tEnter last name : ");
			scanf("%s", name2);
			theList = removeItem(theList, name1, name2);
		}
		else if ( strcasecmp(str, "updateFirst") == 0 ) {
			printf("\tEnter original first name : ");
			scanf("%s", name1);
			printf("\tEnter last name : ");
			scanf("%s", name2);
			printf("\tEnter new first name : ");
			scanf("%s", name3);
			theList = updateFirst(theList, name1, name2, name3);
		}
		else if ( strcasecmp(str, "updateLast") == 0 ) {
			printf("\tEnter first name : ");
			scanf("%s", name1);
			printf("\tEnter original last name : ");
			scanf("%s", name2);
			printf("\tEnter new last name : ");
			scanf("%s", name3);
			theList = updateLast(theList, name1, name2, name3);
		}
		else
			printf("Invalid option specififed - %s\n", str);

		printf("\n\n");
		printf("Enter an option : ");
		scanf("%s", str);
	}
	return 0;
}
