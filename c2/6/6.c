/*Exercise 2−6. Write a function setbits(x,p,n,y) that returns *x with the n bits that begin at position pset to the rightmost *n bits of y, leaving the other bits unchanged.*/

#include<stdio.h>
unsigned setbits(unsigned x,int p,int n, unsigned y);
int main(void)
{
	printf("The desired result is: \n");
        printf("%u \n",setbits((unsigned)12,3,2,(unsigned)57));
}
unsigned setbits(unsigned x,int p,int n, unsigned y)
{
	return ( x & ~(~(~0 << n) << (p+1-n))) | ( (y & (~(~0<<n)) << (p+1-n)));
}

/* Output:-
The desired result is:
8


*/
