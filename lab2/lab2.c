#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "linkedList.h"

#define MAX_LENGTH 41

void removeNewline(char word[], int maxLegth) {
	for (int i = 0; i < maxLegth+1; i++) {
		if (word[i] == '\n') {
			word[i] = '\0';
		}
	}
}

void allToUpper(char word[], int maxLegth) {
	for (int i = 0; i < maxLegth+1; i++) {
		word[i] = toupper(word[i]);
	}
}

void removeSpaces(char word[], int maxLegth) {
	for (int i = 0; i < maxLegth+1; i++) {
		if (word[i] == ' ') {
			word[i] = '\0';
		}
	}
}

void filter(char word[], int maxLegth) {
	removeNewline(word, MAX_LENGTH);
	allToUpper(word, MAX_LENGTH);
	removeSpaces(word, MAX_LENGTH);
}	

int main(void) {
	char inBuf[MAX_LENGTH];
	LinkedList* list = LinkedListConstructor();
	
	for (;;) {
		if (fgets(inBuf, MAX_LENGTH, stdin) != NULL) {
			//removeNewline(inBuf, MAX_LENGTH);
			filter(inBuf, MAX_LENGTH);
			//printf("%s\n", inBuf);
			list->curr = list->tail;
			if (list->curr == NULL) {
				list->curr = newLink(inBuf);
				list->tail = list->curr;
			} else {								
				int wordFoundFlag = 0;
				
				do {					
					if (strcmp(list->curr->word.word, inBuf) == 0) {
						list->curr->word.count++;
						wordFoundFlag = 1;
						//printf("found %s %d \n", list->curr->word.word, list->curr->word.count);
					}
				} while(list->previous(list) && wordFoundFlag == 0);
				list->curr = list->tail;
				if (wordFoundFlag == 0) {
					//printf("%s not found\n", inBuf);
					list->newNext(list, inBuf);
				}
			}
			//list->printList(list);
			/*
			if (strcmp("a", inBuf) == 0) {
				while(strcmp(list->curr->word.word, "a") !=0) {
					list->previous(list);
				}
				printf("%s %d\n",list->curr->word.word, list->curr->word.count);					
				list->curr = list->tail;
			}
			*/
		} else {
			break;
		}		
	}
	list->printList(list);	
}