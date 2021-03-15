/*Exercise 5−3. Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t)copies the string t to the end of s.*/

#include<stdio.h>
#define MAXLINE 1000

int mgetline(char line[],int maxline);	// To get a string of length Maxilne or lesser from user and store it in array line[]
void mystrcat(char *,char *);	// To concate two strings

int main(void)
{
    int len;
    char s[MAXLINE],t[MAXLINE];

    putchar('s');
    putchar(':');
    mgetline(s,MAXLINE);
    
    putchar('t');
    putchar(':');
    mgetline(t,MAXLINE);
    
    mystrcat(s,t);			// It concates string t at the end of string s

    printf("%s",s);

    return 0;
}

int mgetline(char s[],int lim)		// To get a string from the user
{
    int c,i;
    
    for(i=0;i<lim-1 && (c=getchar()) !=EOF && c!='\n';++i)		// It stores the each character given as an input by the user at particular array position
        s[i] = c;
    
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';

    return i;
}

void mystrcat(char *s,char *t)		// It concates string t at the end of string s
{
    while(*s!='\0')		// It goes to the end of string s (at \n)
        s++;
    s--;            
    while((*s=*t)!='\0')		// It stores the characters of string t in string s from ending of string s at position of (\n)
    {   
        s++;
        t++;
    }
}

/* Output :-

s:ab
t:cd
abcd


*/
