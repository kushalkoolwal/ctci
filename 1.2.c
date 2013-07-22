#include<stdio.h>
#include<string.h>

#define BUFF_SIZE 	20

/* interchange l[x] and l[y] */
void swap(char l[], int x, int y) {

	char temp;
	
	temp = l[x];
	l[x] = l[y];
	l[y]= temp;

}

/* reverse string in place */
void mystrrev (char *s) {

	int i, j;

	i=0;
	j = strlen(s)-1;
	while (i < j) {
		swap(s, i, j);
		i++;
		j--;
	}
}

void main (void) {

	char buffer[BUFF_SIZE];

	printf("Enter a string to reverse it:");
	/* scanf adds '\0' character automatically */
	scanf("%s", buffer);
	mystrrev(buffer);
	printf("Reverse String: %s\n", buffer);
}
