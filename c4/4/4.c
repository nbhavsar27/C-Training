/*Exercise 4−4. Add the commands to print the top elements of the stack without popping, to duplicate it, andto swap the top two elements. Add a command to clear the stack.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);	// To get operand from the user's input
void push(double);	// To push the value on a stack
double pop(void);	// To pop the value from a stack

int main(void)
{
    int type;
    double op2,op1;
    char s[MAXOP];
    void clearsp(void);

    while((type = getop(s)) != EOF)	// It will get operands till EOF occurs
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
                        op2 = pop();
                        push(pop()-op2);
                        break;
                case '/':		// This performs Division
                        op2 = pop();
                        if(op2 != 0.0)
                            push(pop()/op2);
                        else
                            printf("error:zero divisor\n");
                        break;
                case '%':		// This performs Modulus Operation
                        op2 = pop();
                        if(op2 != 0.0)
                            push((pop(),op2));
                        else
                            printf("erro:zero divisor\n");
                        break;
                case '?':		// This performs Peek Operation
                        op2=pop();
                        printf("\t%.8g\n",op2);
                        push(op2);
                        break;
                case 'c':		// This will clear the stack
                        clearsp();
                        break;
                case 'd':		// This performs Duplication
                        op2=pop();
                        push(op2);
                        push(op2);
                        break;
                case 's':		// This performs swapping
                        op1=pop();
                        op2=pop();
                        push(op1);
                        push(op2);
                        break;  
                case '\n':		// This performs Popping operation
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

void push(double f)	// To push the value on a stack
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error:stack full, cant push %g\n",f);
}


double pop(void)	// To pop the value from a stack
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clearsp(void)	// To clear the stack
{
    sp = 0;
}

#include<ctype.h>	

int getch(void);
void ungetch(int);

int getop(char s[])	// To get operand from the user's input
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c =='\t')	// It will execute the loop till user enters ' ' or '\t'
        ;
    s[1] = '\0';
    
    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')			// If entered character c is not a digit and not a '.' and not a '-' than it will return c  
        return c;

    if(c=='-')
        if(isdigit(c=getch()) || c == '.')		// It will check whether the entered character is a digit or a '.',if so than it will store the value in the array
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }
    
    if(isdigit(c))
        while(isdigit(s[++i] =c =getch()))		// It will continue the loop execution till numbers entered and will store them in array else will be terminated
            ;

    if(c=='.')						// It will check if the input is a '.'
        while(isdigit(s[++i] = c=getch()))		// It will continue the loop execution till numbers entered and will store them in array else will be terminated
            ;
    
    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100	// It defines buffer size

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();	// If the value of 'bufp'>0 than it will overwrite the value at bufp else will get new character
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)					// It is used for checking buffer overflowing
        printf("ungetch: too many characters\n");
    else				
        buf[bufp++] = c;				// It will store the character in buf array at position 'bufp' than increments the value of 'bufp'
}


/* Output:-


1 2 +
	3

*/


