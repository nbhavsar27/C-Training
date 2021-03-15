/*Exercise 7−3. Revise minprintf to handle more of the other facilities of printf.*/

#include<stdio.h>
#include<stdarg.h>
void minprintf(char *fmt,...);

int main(void)
{
    char *a="Hello,World";
    minprintf("%d %f %s %x abcd 1234\n",10,5.567,a,15);		// It will print values according to the given format
    
    return 0;
}

void minprintf(char *fmt,...)
{
    va_list ap;			// It will initialize the pointer ap to point to the argument list
    char *p,*sval;
    int ival;
    double dval;

    va_start(ap,fmt);  		// It will point the first argument
    
    for(p=fmt;*p;p++)		// It will read each characters of the given string
    {
        if(*p != '%')			// If *p != % than it will print the character as it is and continue the loop without executing the remaining statements inside the loop
        {
            putchar(*p);
            continue;
        }

        switch(*++p)	//  Here *++p denotes next character after % sign
        {
            case 'd':		// It will print integer value
                ival = va_arg(ap,int);
                printf("%d",ival);
                break;
            case 'f':		// It will print double value
                dval = va_arg(ap,double);
                printf("%f",dval);
                break;
            case 's':		// It will print string value
                for(sval = va_arg(ap,char *);*sval;sval++)
                    putchar(*sval);
                break;
	    case 'x':		// It will print hexadecimal value
		ival = va_arg(ap,int);
		printf("%x",ival);
		break;
            default:		// It will print given characters as it is
                putchar(*p);
                break;
        }
    }
    va_end(ap);		//used to denote end of the argument list
}

/* Output:-
10 5.567000 Hello,World f abcd 1234

*/
