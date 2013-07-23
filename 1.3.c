#include<stdio.h>
#include<string.h>

#define BUFF_SIZE 	20


void remove_dup_v2 (char *s) {

	int i, j, k;
	char ch;

	i=j=k=0;

	/* scan all characters in the string */	
	while (s[i] != '\0') {
		ch = s[i];
		/* scan all characters from 'i' onwards to see if 'ch' is present */
		j = i + 1;
		while (s[j] != '\0') {
			if (s[j] == ch) {
				/* shift characters left by one, hence emoving the duplicates */
				k = j;
				while (s[k] != '\0') {
					s[k] = s[k+1];
					k++;
				}
			}
			else {
				j++;
			}
		}
		i++;
	}

}

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
			#if DEBUG
			printf("i=%d j=%d tail=%d\n", i, j, tail);
			#endif
			if (s[i] == s[j])
				break;
		}
		#if DEBUG
		printf("j=%d tail=%d\n", j, tail);
		#endif
		if (j == tail) {
			#if DEBUG
			printf(" %c = %c\n", s[tail], s[i]);
			#endif
			s[tail] = s[i];
			++tail;
		}
	}
	s[tail] = '\0';
}

void main (void) {

	char buffer[BUFF_SIZE];

	printf("Enter a string to reverse it:");
	/* scanf adds '\0' character automatically */
	scanf("%s", buffer);
	remove_dup_v2(buffer);
	printf("String w/o duplicate characters: %s\n", buffer);
	return;
}
