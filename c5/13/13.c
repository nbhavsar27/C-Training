/*Exercise 5−13. Write the program tail, which prints the last n lines of its input. By default, n is set to 10, letus say, but it can be changed by an optional argument so thattail −nprints the last n lines. The program should behave rationally no matter how unreasonable the input or thevalue of n. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEFLINES 5 // default # of lines to print 
#define LINES   100 // maximum # of lines to print 
#define MAXLEN  100 // maximum length of an input line 

void error(char *);
int mgetline(char *,int);

int main(int argc,char *argv[])		//print the last n lines of the input 
{
    char *p;
    char *buf;  // pointer to the large buffer 
    char *bufend;   // end of the large buffer 

    char line[MAXLEN];
    char *lineptr[LINES];   // pointer to lines read 
    
    int first,i,last,len,n,nlines;

    if( argc == 1)		// If argc==1 than it will consider deflines defined in program
        n = DEFLINES;

    else if(argc ==2 && (*++argv)[0] == '-')		// It is used to extract the argument given by the user in command line
        n = atoi(argv[0]+1);
    else
        error("Usage: [-n]");

    if( n < 1 || n > LINES)
            n = LINES;

    for(i = 0; i < LINES; i++)
            lineptr[i] = NULL;

    if(( p = buf = malloc(LINES * MAXLEN)) == NULL)
        error("tail: cannot allocate buf");
    bufend = buf + LINES + MAXLEN;

    last = 0;
    nlines = 0;

    while((len = mgetline(line,MAXLEN)) > 0)
    {
        if(p+len+1 >= bufend)
            p = buf;
        lineptr[last] = p;

        strcpy(lineptr[last],line);
        if(++last >= LINES)
            last = 0;

        p += len + 1;
        nlines++;
    }

    if( n > nlines)
        n = nlines;

    first = last - n;

    if(first < 0)
        first += LINES;
	printf("The last %d lines are:\n",n);    
    for(i= first; n-- > 0;i = (i+1) % LINES)
        printf("%s",lineptr[i]);

    return 0;
}

 

void error(char *s)		// error: print error messages and exit
{
    printf("%s\n",s);
    exit(1);
}

int mgetline(char s[],int lim)		// mgetline: read a line into s and return length 
{
    int c,i;
    
    for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
        s[i] = c;
    if ( c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}


/* Output;-

L1
L2
L3
L4
L5
L6
L7
The last 5 lines are:
L3
L4
L5
L6
L7


./a.out “-3”
L1
L2
L3
L4
L5
The last 3 lines are:
L3
L4
L5


*/

