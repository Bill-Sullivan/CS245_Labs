#include <stdio.h>
#include <string.h>

#include "linkedList.h"

#define MAX_LENGTH 41

void removeNewline(char word[], int maxLegth) {
	for (int i = 0; i < maxLegth+1; i++) {
		if (word[i] == '\n') {
			word[i] = '\0';
		}
	}
}

int main(void) {
	char inBuf[MAX_LENGTH];
	LinkedList* list = LinkedListConstructor();

	while (1) {
		if (fgets(inBuf, MAX_LENGTH, stdin) != NULL) {
			removeNewline(inBuf, MAX_LENGTH);
			if (list->curr == NULL) {
				list->curr = newLink(inBuf);
			} else {
				if (strcmp(list->curr->word.word, inBuf) == 0) {
					list->curr->word.count++;
				} else {
					list->newNext(list, inBuf);
				}
			}
			printf("%s\n",inBuf);
		}
	}
	
}