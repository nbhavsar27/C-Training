/*Exercise 5−10. Write the program expr, which evaluates a reverse Polish expression from the commandline, where each operator or operand is a separate argument. For example,expr 2 3 4 + *evaluates 2 * (3+4).*/

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXVAL 100

int getop(char *s);
void push(int);
int pop(void);
int sp = 0;		
int val[MAXVAL];		
int main(int argc, char *argv[])
{
	int op2, type;
	if(argc == 1)	// It checks value of arc and if it is 1 than it will terminate the program
	{
		printf("Usage: \"num1\" \"num2\" \"[num3 ..]\" \"oper1\" \"[oper2 ...]\"\n");
		return -1;
	}else
	{
		while(--argc > 0){
			type = getop(*++argv);
			
			switch(type)
			{
				case '0':		// This is used to convert string to integer

					push(atoi(*argv));
					break;
				case '+':		// This performs Addition
					push(pop() + pop());
					break;
				case 'x':		// This performs Multiplication
					push(pop() * pop());
					break;
				case '-':		// This performs Substraction
					op2 = pop();
					push(pop() - op2);
					break;
				case '/':		// This performs Division
					op2 = pop();
					if(op2 != 0)
						push(pop() / op2);
					else{
						printf("error. division by zero\n");
						return -1;
					}
					break;
				default:
					printf("error. invalid argument %s\n", *argv);
					return -1;
			}
		}
	}
	printf("%d\n", pop());

	return 0;
}

int getop(char *s) 	// To get operands from given arguments
{
	int c;
	while(isdigit(c = *s++))		// It will be executed till numbers are entered
		;
	if(c == '\0')
		return '0';
	else
		return c;
}




void push(int i) 	 // To push the number in stack
{
	if(sp > MAXVAL)
		printf("error. stack full\n");
	else
		val[sp++] = i;
}

int pop(void)	 // To pop the number from stack
{
	if(sp <= 0)
		printf("error. stack empty\n");
	else
		return val[--sp];
}

/* Output:_

2 3 4 + *
		14

*/


