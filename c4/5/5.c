/*Exercise 4−5. Add access to library functions like sin, exp, and pow. See <math.h>*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int top=-1;
int data[10];
void push(int temp)		// To push the value on a stack
{
	if(top==9)			// It will check upper limit
		printf("stack is full");
	else
	{
		
		data[++top]=temp;
	}
}
int pop()			// To pop the value from a stack
{
	if(top==-1)		// It will check whether the stack is empty or not
		printf("stack is empty");
	else
	{
	
		int a=data[top--];
		return(a);
	}

}

void peek()		// It will show the top element in stack
{

	if(top==-1)
		printf("stack is empty");
	else
		printf("%d",data[top]);
}
int main ()
{

int ch,s1,s2;

int temp,i;
while(1)		// Infinite Loop
{

printf("\n*****STACK OPERATIONS*****\n");
printf("\n 0.view stack\n 1.Push\n 2.Pop\n 3.peek\n 4.Duplicate\n 5.Swap\n 6.Sine\n 7.Cosine\n 8.sqrt()\n 9.power\n 10.Clear\n 11.Exit\n");
printf("\nEnter the choice: ");
scanf("%d",&ch);
		if(ch==0)		// It will view stack
		{
			for(i=top;i>=0;i--)
			printf("%d\n",data[i]);		
		}

		
		if(ch==1)		// It will push value in stack
		{
			printf("\nEnter an element to be pushed:\n");
			scanf("%d",&temp);
			push(temp);
			
		
		}
		

		if(ch==2)		// It will pop value from stack
		{
			pop();
			
		}		
	
		
		if(ch==3)		// It will show the top element of stack
		{
			peek();
		}
		

		if(ch==4)		// It will perform duplication of the top element in the stack
		{ 
			if(top==-1)		// It will check whether the stack is empty or not
			{
				printf("Can't duplicate! Stack is empty!!\n");
			}
			else
			{
			printf("Before Duplicating\n");
			for(i=top;i>=0;i--)
			printf("%d\n",data[i]);
			s1=pop();
			push(s1);
			push(s1);
			printf("after Duplicating\n");
			for(i=top;i>=0;i--)
			printf("%d\n",data[i]);
			}
		}
		
		
		if(ch==5)		//  It will perform swapping operation

		{
			if(top>0)
			{
			printf("Before Swaping\n");
			for(i=top;i>=0;i--)
			printf("%d\n",data[i]);
			s1=data[top];
			data[top]=data[top-1];
			data[top-1]=s1;			
			printf("After swaping\n");
			for(i=top;i>=0;i--)
			printf("%d\n",data[i]);		
			}
			else
			{
				printf("Can't swap insufficient elements!\n");
			}
		}
		
		/*if(ch==6)		// It will give sin value of top element
		{
			s1=sin(pop());
			printf("\nsin of top element:\n%d",s1);
		}
		if(ch==7)		// It will give cos value of top element
		{
			s1=cos(pop());
			printf("\ncos of top element:\n%d",s1);
		}
		
		if(ch==8)		// It will perform sqrt function of top element
		{
			if(top==-1)		// It will check whether the stack is empty or not
			{
				printf("Can't find the square root! Stack is empty!! \n");
			}
			else
			{
			s1=sqrt(pop());
			printf("\nSquare root of of top element:\n%d",s1);
			}
		}
		if(ch==9)		// It will execute power operation
		{
			if(top>0)
			{
			s1=pop();
			s2=pop();
			s1=pow(s1,s2);
			printf("\npower of top two element:\n%d",s1);		
			}
			else
			{
				printf("Stack is empty!! can't find the power! \n");
			}
		}*/
		if(ch==10)		//clear stack
			top=-1;
		if(ch==11)		//program termination
			exit(0);

	}

return 0;
}

