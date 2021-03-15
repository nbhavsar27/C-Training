/*Exercise 3−5. Write the function itob(n,s,b) that converts the integer n into a base b characterrepresentation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.*/

#include<stdio.h>
#include<string.h>

#define MAXLINE 100

void itob(int n,char s[],int b);
void reverse(char s[]);

int main(void)
{
    int number,base;
    char str[MAXLINE];
    printf("Enter Number :");
    scanf("%d",&number);
    printf("Enter Base :");
    scanf("%d",&base);

    itob(number,str,base);

    printf("%s\n",str);

    return 0;
}

void itob(int n,char s[],int b)
// It will convert integer n into base b provided by the user.
{
    int i,j,sign;

    if((sign=n)<0)
        n = -n;

    i = 0;

    do
    {
        j = n % b;

        s[i++] = (j <= 9)?j+'0':j+'a'-10;
    }while((n/=b)>0);

    if(sign < 0)
        s[i++]='-';
    
    s[i]='\0';
    
    reverse(s);
}

void reverse(char s[])
//It will reverse the obtained string.
{
    int i,j,c;

    for(i=0,j=strlen(s)-1;i<j;i++,j--)
        c=s[i],s[i]=s[j],s[j]=c;
}


/* Output:-

Enter Number :345
Enter Base :4
11121

*/
