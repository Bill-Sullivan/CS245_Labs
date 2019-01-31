#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define MAX_LENGTH 41

typedef struct wordCounter
{
	char word[MAX_LENGTH];
	int count;
} wordCounter;

typedef struct Link
{
	wordCounter word;
	struct Link* nxt;
	struct Link* prv;
} Link;

Link* newLink(char word[MAX_LENGTH]) {
	Link* newLink = malloc(sizeof(Link));
	strcpy(newLink->word.word, word);
	newLink->word.count = 1;
	return newLink;
}

typedef struct LinkedList
{
	Link* curr;	
	Link* tail;	
	int (*next)(struct LinkedList*);
	int  (*newNext)(struct LinkedList*, char [MAX_LENGTH]);
	int  (*previous)(struct LinkedList*);
	void (*printList)(struct LinkedList*);	
} LinkedList;

int next(LinkedList* list) {
	if (list->curr->nxt != NULL) {
		list->curr = list->curr->nxt;
		list->tail = list->curr;
		return 1;
	} else {
		return 0;
	}
}

int newNext(LinkedList* list, char newString[MAX_LENGTH]) {
	Link* next = newLink(newString);
	list->tail = next;
		if (next != NULL) {
			next->prv = list->curr;			
			list->curr = next;
		}
}

int previous(LinkedList* list) {
	if (list->curr->prv != NULL) {
		list->curr = list->curr->prv;
		return 1;
	} else {
		return 0;
	}
}

void printList(LinkedList* list) {
	list->curr = list->tail;
	printf("\n\nprinting list\n");
	printf("%s %d \n", list->curr->word.word, list->curr->word.count);
	while (list->previous(list)) {
		printf("%s %d \n", list->curr->word.word, list->curr->word.count);
	}
	list->curr = list->tail;
}

LinkedList* LinkedListConstructor() {
	LinkedList* newList = malloc(sizeof(LinkedList));
	newList->next = next;
	newList->previous = previous;
	newList->newNext = newNext;
	newList->printList = printList;
	return newList;
}