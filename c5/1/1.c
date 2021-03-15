/*Exercise 5−1. As written, getint treats a + or − not followed by a digit as a valid representation of zero.Fix it to push such a character back on the input.*/

#include<stdio.h>
#include<ctype.h>

#define SIZE 5
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;


int getch(void)
{
    return (bufp > 0)? buf[--bufp] : getchar();		// If the value of 'bufp'>0 than it will overwrite the value at bufp else will get new characte
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)		// It is used for checking buffer overflowing
        printf("ungetch: too many characters\n");
    else
        buf[bufp++]=c;				// It will store the character in buf array at position 'bufp' than increments the value of 'bufp'
}


int getint(int *pn)
{
    int c,sign;

    while(isspace(c=getch()))	// It will continue the loop if the ‘ ‘ occurs else will terminate the loop
        ;

    if(!isdigit(c) && c !=EOF && c!='+' && c!='-')	// If entered character c is not a EOF and is not a digit and not a ‘+’ and not a '-'  than it will terminate 
    {
        ungetch(c); 	// it's not a number 
        return -1; 		// -1 will end the program directly 
    }

    sign = (c == '-') ? -1 : 1;		// To store the sign of the number

    if(c=='+' || c=='-')		// If the value of c is ‘+’ or ‘-‘ the it will get new character
        c = getch();
    // This avoids to treat a '+' or '-' not followed by a digit as a valid representation of zero 
    if( !isdigit( c ) )		// If not a number than returns 0
            return 0;
    for(*pn = 0; isdigit(c);c=getch())		// To get the consecutive digits of a number to form a number and will store it at given location
        *pn = 10 * *pn + (c-'0');

    *pn *= sign;

    if(c!=EOF)	//checks for c!=EOF
        ungetch(c);

    return c;
}

int main(void)
{
    int n,s,array[SIZE];
    
    for(n=0;n<SIZE && getint(&array[n]) !=EOF;  n++ )		// To store the inputs at consecutive array position 
    {
       printf("storing in n = %d, getint %d\n", n, array[n]);
    }
	printf("The array is: ");
    for(s=0;s<n; s++)		//To print the value of array
        printf("%d ",array[s]);
	printf("\n");

    return 0;
}



/* Output:-

1
Storing in n = 0, getint 1
2
Storing in n = 1, getint 2
3
Storing in n = 2, getint 3
-4
Storing in n = 3, getint -4
5
Storing in n = 4, getint 5
The array is: 1 2 3 -4 5

*/
