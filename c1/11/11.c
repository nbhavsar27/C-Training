/*Exercise 1−11. How would you test the word count program? *What kinds of input are most likely to uncoverbugs if there *are any?*/

#include <stdio.h>
/* count lines, words, and characters in input */
int main()
{
int c, nl, nw, nc;
nl = nw = nc = 0;
while ((c = getchar()) != EOF) 
	{
	++nc;
	if (c == '\n')
	++nl;
	if (c == ' ' || c == '\n' || c == '\t')
	++nw;
}
printf("No.of lines = %d\nNo.of words = %d\nNo.of characters = %d\n",nl,nw,nc-1);
}

/* Output:-

Dhaval
No. of lines = 1
No. of words = 1
No. of characters = 6
*/
