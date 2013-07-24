#include<stdio.h>
#include<string.h>
#define BUFF_SIZE 	20
#define TRUE  		1
#define FALSE 		0

typedef int boolean;


/* interchange l[x] and l[y] */
void swap(char l[], int x, int y) {

	char temp;
	
	temp = l[x];
	l[x] = l[y];
	l[y]= temp;

}

/* string sort function using bubble sort */
char *sortstr (char *s) {

	int i, j, n;

	n = strlen(s);	
	for (i=n-2; i >=0; i--)
		for (j=0; j<=i; j++)
			if (s[j] > s[j+1])
				swap (s, j, j+1);

	return s;
}

/* Return TRUE if anagram, else return FALSE */
boolean check_anagrams (char *s, char *t) {

	sortstr(s);
    sortstr(t);

	if (strcmp(s, t) == 0)
		return TRUE;
	else
		return FALSE;
}

void main (void) {

	char buffer[BUFF_SIZE];
	char buffer1[BUFF_SIZE];

	printf("Enter a string1:");
	/* scanf adds '\0' character automatically */
	scanf("%s", buffer);
	printf("Enter a string2:");
	scanf("%s", buffer1);
	if (check_anagrams (buffer, buffer1))
		printf("Strings are anagrams\n");
	else
		printf("Strings are not anagrams\n");

}
