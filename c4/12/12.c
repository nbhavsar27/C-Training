/*Exercise 4−12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.*/

#include<stdio.h>
#include<math.h>

#define MAXLEN 100

void itoa(int n,char s[]);


int main(void)
{
    int n;
    char s[MAXLEN];
    printf("Enter Number:");
    scanf("%d",& n); 
   

    itoa(n,s);		// It is a user defined function which will do the  conversion of integer to string
    printf("Output:- %s\n",s);

    return 0;
}

void itoa(int n,char s[])
{
    static int i;

    if(n/10)		// It call itself until the value of n/10 is ==0
        itoa(n/10,s);
    else		
    {
        i = 0;
        if( n < 0)		// If n< 0 than ‘-‘ is stored at s[0]
            s[i++]='-';
    }
    
    s[i++] = (n) % 10 + '0';		//It will extract the last digit from a number

    s[i] = '\0';

}

/* 
Output :-

Enter Number:1234
Output:- 1234

*/
