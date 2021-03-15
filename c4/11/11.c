/*Exercise 4−11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal staticvariable.*/

#include<stdio.h>
#include<stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);		// To get operand from the user's input
void push(double);		// To push the value on a stack
double pop(void);		// To pop the value from a stack

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF)		// It will get operands till EOF occurs

    {
        switch(type)
        {
            case NUMBER:		// This is used to convert string to float
                    push(atof(s));
                    break;
            case '+':		// This performs Addition

                    push(pop()+pop());
                    break;
            case '*':		// This performs Multiplication
                    push(pop()*pop());
                    break;
            case '-':		// This performs Substraction
                    op2=pop();
                    push(pop()-op2);
                    break;
            case '/':		// This performs Division
                    op2=pop();
                    if(op2 != 0.0)
                        push(pop()/op2);
                    break;
            case '\n':	// This performs Popping operation
                    printf("\t%.8g\n",pop());
                    break;
            default:
                    printf("error: unknown command %s\n",s);
                    break;
        }
    }
    return 0;
}


#define MAXVAL 100	// It defines maximum number of inputs user can enter

int sp = 0;		// sp stands for stack pointer
double val[MAXVAL];



void push(double f)		// To push the value on a stack
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full,can't push %g\n",f);
}


double pop(void)		// To pop the value from a stack
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include<ctype.h>

int getch(void);


int getop(char s[])	// To get operand from the user's input
{
    int c,i;
    static int lastc = 0;

    if(lastc == 0)		// If the lastc is ==0 than it will obtain new character from the user
        c = getch();
    else
    {
        c = lastc;
        lastc = 0;
    }

    while((s[0]=c) == ' ' || c == '\t')		// It will execute the loop till user enters ' ' or '\t'
        c = getch();
    
    s[1]='\0';
    
    if(!isdigit(c) && c!= '.')		// If entered character c is not a digit and not a '.'  than it will return c 
        return c;
    
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] =c=getch()))		// It will continue the loop execution till numbers entered and will store them in array else will be terminated
            ;
    if(c=='.')		// It will check if the input is a '.'
        while(isdigit(s[++i] =c=getch()))		// It will continue the loop execution till numbers entered and will store them in array else will be terminated
            ;
    s[i]='\0';
    
    if(c!=EOF)
        lastc=c;

    return NUMBER;
}

#define BUFSIZE 100		// It defines buffer size

char buf[BUFSIZE];
int bufp;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();		// If the value of 'bufp'>0 than it will overwrite the value at bufp else will get new character
}


/* Output:-

1 2 +
	3

*/
