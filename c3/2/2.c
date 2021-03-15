/*Exercise 3−2. Write a function escape(s,t) that converts characters like newline and tab into visibleescape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the otherdirection as well, converting escape sequences into the real characters.*/


#include<stdio.h>
#define MAXLINE 1000
int mgetline(char line[],int maxline);
void escape(char s[],char t[]);


int main(void)
{
    char s[MAXLINE],t[MAXLINE];

    mgetline(t,MAXLINE);

    escape(s,t);

    printf("%s\n",s);

    return 0;
}

void escape(char s[],char t[])
{
    int i,j;

    i=j=0;

    while(t[i] != '\0')
    	{
	   switch(t[i])
           {
            case '\t':
                    s[j]='\\';
                    ++j;
                    s[j]='t';
                    break;
            case '\n':
                    s[j]='\\';
                    ++j;
                    s[j]='n';
                    break;
            default:
                    s[j]=t[i];
                    break;
          }
           ++i;
           ++j;
       }
    
    s[j]='\0';
}

int mgetline(char s[],int lim)
{
    int i,c;

    for(i=0;i<lim-1 && (c=getchar())!=EOF;++i)
        s[i]=c;

    s[i]='\0';
}

/* Output:-

ab	cd
ef
ab\tcd\nef  (here the "tab" is replaced by "\t" and "enter" is replaced by "\n(new line character)")


*/
