#ifndef CS100MLIST
#define CS100MLIST

typedef struct node {
	char *first;
	char *last;
	long number;
	struct node *nextFirst;
	struct node *nextLast;
} Node;

typedef struct mlist {
	Node *headFirstName;
	Node *headLastName;
} MultiLinkedList;

#endif

///////////////////////////////////////////////////////////////

int size(MultiLinkedList *);
void printByFirst(MultiLinkedList *);
void printByLast(MultiLinkedList *);

int lookup(MultiLinkedList *, char *);
void updatePhone(MultiLinkedList *, char *, char *, long);

MultiLinkedList *add(MultiLinkedList *, char *, char *, long);
MultiLinkedList *removeItem(MultiLinkedList *, char *, char *);
MultiLinkedList *updateFirst(MultiLinkedList *, char *, char *, char *);
MultiLinkedList *updateLast(MultiLinkedList *, char *, char *, char *);
