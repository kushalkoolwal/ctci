#include<stdio.h>
#include<string.h>
#define BUFF_SIZE 	50
#define TRUE  		1
#define FALSE 		0

typedef int boolean;


/* function to replace "space" with "%20" */
void str_replace (char *s) {

	int i, len, space_count, new_len;

	i=len=space_count=new_len=0;

	len = strlen(s);

	/* count number of spaces in the string */
	for(i=0; i<len; i++)
		if (s[i] == ' ')
			space_count++;

	/* calculate new length of array */
	new_len = len + (space_count * 2);

	/* delimit the resized array */
	s[new_len] = '\0';

	/* scan string from backwards and do the replacement/shifting the array */
	for (i=len-1; i>=0; i--) {
		/* replace every space with '%20' */
		if (s[i] == ' ') {
			s[new_len-1] = '0';
			s[new_len-2] = '2';
			s[new_len-3] = '%';
			new_len = new_len-3;
		}
		/* shift the characters to their new location */
		else {
			s[new_len-1] = s[i];
			new_len--;
		}	
	}
}

void main (void) {

	char buffer[BUFF_SIZE];

	printf("Enter a string:");
	/* scanf adds '\0' character automatically */
	/*scanf("%s", buffer);*/
	scanf("%[^\n]s", buffer);
	/* fgets adds '/n' character at the end */
	/*fgets (buffer, BUFF_SIZE, stdin);*/
	str_replace(buffer);
	printf("String after replacement:%s\n", buffer);

}
