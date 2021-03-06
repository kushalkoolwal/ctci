#include<stdio.h>
#define BUFF_SIZE 	20
#define TRUE  		1
#define FALSE 		0

typedef int boolean;

/* Return TRUE if unique characters, else return FALSE */
boolean check_unique (char *s) {

	
	int charset[127];	/*assuming we have ASCII set of 127 characters */
	int i, val;

	i = 0;
	while (s[i] != '\0') {
		val = s[i];		/* comment this line to get a "bus error" */
		/* we have seen this character before return FALSE */
		if (charset[val] == 1)
			return FALSE;
		/* store '1' for a brand new character */
		charset[val] = 1;
		i++;
	}
	return TRUE;
}

/* same as above function but without extra variables
   we use a bit vector (int check_bv) to check for repeating characters
   sizeof(int) on this machine is 32, therefore we can easily accomodate a-z
   on this system.
 */
boolean check_unique_novar (char *s) {

	int i, val, check_bv=0;

	i = 0;
	while (s[i] != '\0') {

		/* ASCII of 'a' is 97 */
		val = s[i] - 'a';
		/* check status of bit 'val' */
		if ((check_bv & (1 << val)) > 0)		
			return FALSE;
		/* set the bit 'val' */
		check_bv = check_bv | (1 << val);
		i++;
	}
	return TRUE;
}

void main (void) {

	char buffer[BUFF_SIZE];

	printf("Enter a string to check for unique characters:");
	/* scanf adds '\0' character automatically */
	scanf("%s", buffer);
	if (check_unique_novar (buffer))
		printf("String has unique characters\n");
	else
		printf("String has repeating characters\n");

}
