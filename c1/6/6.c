/*Exercsise 1−6. Verify that the expression getchar() != EOF is *0 or 1.*/

#include<stdio.h>
int main(void)
{
	char c;
	printf("Enter any character: \n");
	c=getchar();
	printf("Value of EOF : %d \n",c != EOF);
}

/* Output:-
Enter any character:
dhaval
Value of EOF : 1

It will terminate the loop when the EOF(control+d) occurs

*/
