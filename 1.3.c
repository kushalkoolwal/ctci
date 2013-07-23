#include<stdio.h>
#include<string.h>

#define BUFF_SIZE 	20

/* remove duplicate characters from string without additional array
   scan every character in the string and compare it with all the previous
   characters. If duplicate we skip the character, otherwise copy it 	
 */

void remove_dup (char *s) {

	int i, j, len, tail=1;

	len = strlen(s);

	if (len < 2 || len == 0)
		return;

	for (i=1; i < len; i++) {
		for (j = 0; j < tail; j++) {
			if (s[i] == s[j])
				break;
		}
		if (j == tail) {
			s[tail] = s[i];
			++tail;
		}
	}
	s[tail] = 0;
}

void main (void) {

	char buffer[BUFF_SIZE];

	printf("Enter a string to reverse it:");
	/* scanf adds '\0' character automatically */
	scanf("%s", buffer);
	remove_dup(buffer);
	printf("String w/o duplicate characters: %s\n", buffer);
}
