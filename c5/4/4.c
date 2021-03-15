/*Exercise 5−4. Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.*/


#include<stdio.h>
#define MAXLINE 1000

int mgetline(char s[],int max);	// To get a string from user 
int strend(char *s,char *t);		// It performs the required function
int mystrlen(char *t);			// To get length of string

int main(void)
{
    char s[MAXLINE],t[MAXLINE];
    int ret;
    mgetline(s,MAXLINE);		// To get string s from user
    mgetline(t,MAXLINE);		// To get string t from user
    ret = strend(s,t);			// To store the value returned by the function
    printf("%d\n",ret);
    return 0;
}

int mgetline(char s[],int lim)	// To get a string from user
{
    int c,i;
    
    for(i=0;i<lim-1 && ((c=getchar())!=EOF) && c!='\n';++i)		// It stores the each character given as an input by the user at particular array position

        s[i]=c;

    if(c=='\n')
    {
        s[i]=c;
        ++i;
    }
    s[i]='\0';

    return i;
}

int strend(char *s,char *t)		// It returns 1 if the string t occurs at the end of the string s, and zero otherwise.
{
    int len;
    len=mystrlen(t);
    while(*s!='\0')			// To reach at the end of the string s
        ++s;
    --s;

    while(*t!='\0')			// To reach at the end of the string t
        ++t;
            
    --t;
    while(len > 0)			// To check that string t occurs at the end of string s
    {
        if(*t==*s)
        {
            --t;
            --s;
            --len;
        }
        else
            return 0;
    }
    if( len == 0)			// It len==0 than it will return 1 ( string t occurs at the end of string s)
        return 1;
}

int mystrlen(char *t)		// To get length of string
{
    char *p;
    p=t;

    while(*p!='\0')			// To reach at the end of the string
        ++p;

    return p-t;			// It will return the length
}

/* Output:-

abcd
cd
1

*/
