/*Exercise 5−7. Rewrite readlines to store lines in an array supplied by main, rather than calling alloc tomaintain storage. How much faster is the program?*/

#include<stdio.h>
#include<string.h>

#define MAXLINES 5000   // max #lines to be sorted 

char *lineptr[MAXLINES];		// It is used to store address of each line
char linestor[MAXLINES];		// It is used to store line

int readlines(char *lineptr[],char *linestor,int nlines);		// It is used to read lines given as input from the user
void writelines(char *lineptr[],int nlines);				// It is used to write lines at specified address
void qsort(char *lineptr[],int left,int right);				// It is used for sorting

// sort input lines 

int main(void)
{
    int nlines; //  number of input lines read 

    if((nlines = readlines(lineptr,linestor,MAXLINES)) >= 0)		// If value of liner is >=0 than it will sort and than store and prints
    {
        qsort(lineptr,0,nlines-1);
	printf("\n\n");
        writelines(lineptr,nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort \n");
        return 1;
    }
}

#define MAXLEN 1000 // max length of any input line 
#define MAXSTOR 5000

int mgetline(char *,int);		// To get a string from user
char *alloc(int);

// readlines: read input lines 
int readlines(char *lineptr[],char *linestor,int maxlines)
{
    int len,nlines;
    char line[MAXLEN];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;

    nlines=0;

    while((len=mgetline(line,MAXLEN)) > 0)
        if(nlines >= maxlines || p+len > linestop)		
            return -1;
        else
        {
            line[len-1] = '\0';
            strcpy(p,line);
            lineptr[nlines++]=p;
            p+=len;
        }
    return nlines;
}

// writelines: write output lines 
void writelines(char *lineptr[],int nlines)
{
    int i;
    for(i=0;i<nlines;i++)
        printf("%s\n",lineptr[i]);
}

// qsort: sort v[left] ... v[right] into increasing order 
void qsort(char *v[],int left,int right)		// Used for sorting
{
    int i,last;
    void swap(char *v[],int i,int j);

    if(left >= right)
        return;
    swap(v,left,(left+right)/2);

    last = left;

    for(i=left+1;i<=right;i++)
        if(strcmp(v[i],v[left])<0)
            swap(v,++last,i);
    swap(v,left,last);
    qsort(v,left,last-1);
    qsort(v,last+1,right);
}

// swap: interchange v[i] and v[j] 

void swap(char *v[],int i,int j)		// It is used for swapping 
{
    char *temp;

    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}

#define ALLOCSIZE 10000  // size of available space 

static char allocbuf[ALLOCSIZE];    // storage for alloc 
static char *allocp = allocbuf;     // next free position 

char *alloc(int n)  // return pointer to n characters 
{
    if(allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp -n;
    }
    else
        return 0;
}

int mgetline(char *s,int lim)		// To get a string from user
{
    int c;
    char *t=s;

    while(--lim >0 && (c=getchar())!=EOF && c!='\n')		// It stores the each character given as an input by the user at particular address
        *s++ = c;
    if( c == '\n')
        *s++ = c;

    *s= '\0';

    return s-t;
}


/* Output:-

A
B
D
C
F
E


A
B
C
D
E
F


*/
