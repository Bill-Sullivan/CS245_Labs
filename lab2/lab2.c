#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 41

typedef struct
{
	char[MAX_LENGTH] word;
	int count;
} wordCounter;

void removeNewline(char word[], int maxLegth) {
	for (int i = 0; i < maxLegth; i++) {
		if (word[i] == '\n') {
			word[i] = '\0';
		}
	}
}

int main(void) {
	char inBuf[MAX_LENGTH];
	fgets(inBuf, MAX_LENGTH)
}