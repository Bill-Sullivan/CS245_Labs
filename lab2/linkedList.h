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
	int (*next)(struct LinkedList*);
	int (*newNext)(struct LinkedList*, char [MAX_LENGTH]);
	int (*previous)(struct LinkedList*);
} LinkedList;

int next(LinkedList* list) {
	if (list->curr->nxt != NULL) {
		list->curr = list->curr->nxt;
		return 1;
	} else {
		return 0;
	}
}

int newNext(LinkedList* list, char newString[MAX_LENGTH]) {
	Link* next = newLink(newString);
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

LinkedList* LinkedListConstructor() {
	LinkedList* newList = malloc(sizeof(LinkedList));
	newList->next = next;
	newList->previous = previous;
	newList->newNext = newNext;
	return newList;
}