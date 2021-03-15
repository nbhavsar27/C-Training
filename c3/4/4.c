/*Exercise 3−4. In a two's complement number representation, *our version of itoa does not handle the largestnegative *number, that is, the value of n equal to −(2wordsize−1). *Explain why not. Modify it to print that valuecorrectly, *regardless of the machine on which it runs.*/


#include<stdio.h>
#include<string.h>
void itoa( int , char *);
void reverse(char *);
int main()
{
	char s[50];
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	itoa(n,s);
}
void itoa(int n, char s[])
// This will convert n to characters in s
{
	int i, sign;
	if ((sign = n) < 0) /* record sign */
		n=-n; /* make n positive */
	i = 0;
	do { /* generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */
	reverse(s);
}


void reverse(char s[])
// This function will reverse the obtained string.
{
	int i,j;
	int count=0;
	char s1[50];
	for (i=0;s[i]!='\0';i++)
	{
		count++;
	}
	for(i=0,j=count-1;i<count,j>=0;i++)
	{
		s1[j]=s[i];
		j--;
	}
	printf("Number converted to string is: ");
	for(i=0;i<count;i++)
	{
		printf("%c",s1[i]);

	}
	printf("\n");
}

/* Output:-

Enter Number:123
Number 123 converted to string as :123

*/
