#include<stdio.h>
#include<string.h>
#define BUFF_SIZE 	20
#define TRUE  		1
#define FALSE 		0

typedef int boolean;


/* check whether 't' is a substring of 's' or not */
boolean mystrstr (char *s, char *t) {

	int i, j, k;

	for (i = 0; s[i]; i++) {
		for (j = i, k = 0; t[k] && s[j] == t[k]; j++, k++);
       		if (k > 0 && !t[k])
               	return TRUE;         
	}
    return FALSE;
}


/* function to check if s2 is a rotation of s1 */
boolean check_rotation (char *s1, char *s2) {

	/* check is length of s1 and s2 are same and > 0 */
	if ((strlen(s1) == strlen(s2)) &&  (strlen(s1) > 0)) {
		strcat(s1, s1);		
		return mystrstr(s1, s2);
	}
	return FALSE;
}

void main (void) {

	char buffer[BUFF_SIZE];
	char buffer1[BUFF_SIZE];

	printf("Enter string1:");
	/* scanf adds '\0' character automatically */
	scanf("%s", buffer);
	printf("Enter string2:");
	scanf("%s", buffer1);
	if (check_rotation (buffer, buffer1))
		printf("S2 is rotation of S1\n");
	else
		printf("S2 is not a rotation of S1\n");
}
