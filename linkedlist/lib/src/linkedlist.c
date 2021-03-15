#include "../inc/linkedlist.h"

int i = 0;

void createlist(int n)	// To Create List containing of nodes
{
	int data = 0;
	if(n>=1)
	{	
		printf("Enter the data for node 1 : ");
		scanf("%d",&data);
		struct node *newp2;
		newp2 = malloc(sizeof(struct node));	// Creates new node
		newp2->data = data;		// Assignes data in the data Segment of the List
		newp2->link = NULL;		// Assignes 'NULL' in the link segment of the   List
		head = newp2;			// Assignes the address of the node to the 'head' pointer
		i++;
		for(int j = 2;j<=n;j++)
		{
			printf("Enter the data for node %d : ",j);
			scanf("%d",&data);
			struct node *newp;
			struct node *newp1 = head;
			newp = malloc(sizeof(struct node));	// Creates new node
			newp->data = data;		// Assignes data in the data Segment of the List
			newp->link = NULL;		// Assignes 'NULL' in the link segment of the   List
			while(newp1->link != NULL)	// Checks whether the Link segment    of the List is 'NULL' or not??
				newp1 = newp1->link;	
			newp1->link = newp;
			i++;
		}
	}
}




void print_node(struct node *ptr)	// To Display the List
{
	if(ptr == NULL)		// Checks whether the value of ptr pointer is 'NULL'
		printf("Empty linked list");
	while(ptr != NULL)	// Executes the loop until end node occurs with the link part 'NULL'
	{
		printf("\n%d\n",ptr->data);	// Prints the data value of current node
		ptr = ptr->link;		// Points to the next node
	}
}




void add_begin(int a)	// To add node from Begining of the List
{
		
		node_begin(a);	// Calling function node_begin
}




struct node* node_begin(int a)
{
	struct node *c;
	c = malloc(sizeof(struct node));	// Creates new node
	c->data = a;		// Assignes 'a' in the data segment of the List
	c->link = NULL;		// Assignes 'NULL' in the link segment of the List
	c->link = head;		// Assignes the value of 'head' to the to the link segment of the new node
	head = c;
	i++;
}




void add_node(int a)	// To add node at End of the List
{
	if(head == NULL)
		printf("\nThere is no lined present please create it first\n");	
	else
	{	scanf("%d",&a);
		struct node *newp;
		struct node *newp1 = head;
		newp = malloc(sizeof(struct node));	// Creates new node
		newp->data = a;		// Assignes 'a' to the data segment of the List
		newp->link = NULL;	// Assignes 'NULL' to the link segment of the List
		while(newp1->link != NULL)	// It executes itself till the end node 
		newp1 = newp1->link;	// Updating the value of the pointer in such a way that it points to the next node
		newp1->link = newp;	// It updates the previous Link segment with the address of the node with the help op pointer
		i++;
	}
}





void pos_node(struct node *ptr,int a ,int pos)	// To add node at Specific Position specified in the List
{
	int c = pos-1;
	if(ptr == NULL)
		printf("\nThere is no linked list present please create it first\n");
	if(pos == 1)
	{
		printf("\nEnter the data\n");
		scanf("%d",&a);
		node_begin(a);		// Calling node_begin
	}
	else if (pos == i)
	{
		add_node(a);		// Calling add_node 
	}
	else if(pos>i)
		printf("\nInvalid position\n");
	else
	{
		printf("\nEnter the data\n");
		scanf("%d",&a);
		struct node *b;
		b = malloc(sizeof(struct node));	// Creates new node
		b->data = a;
		while(c)		// It executes itself until the specific position occurs
		{
			ptr = ptr->link;		// It points to the next node 
			c--;
		}
		b->link = ptr->link;	// Updating the link segment of the new created node
		ptr->link = b;		// Updating the link segment of the previous node
		i++;
	}
}




struct node* del_begin()	// To Delete node from Begining of the List
{
	if(head == NULL)
		printf("\nThere is no element to delete\n");	
	else
	{	
		struct node *del = head;	// Creates a del pointer
		head = head->link;	// It moves head pointer to the next node
		free(del);		// It frees the memory
		del = NULL;		// 'NULL'is assigned tu del as it contains invalid memory function
		i--;
		if(i == 0)
			head = NULL;
	}
}




void del_end()	// To Delete node at End of the List
{	if(head == NULL)
		printf("\nThere is no element to delete\n");
	else
	{
		struct node *en = head;		// Creating a en pointer (pointing to the node which is to be deleted,IT INITIALLY POINTS TO FIRST NODE OF THE LIST)
		struct node *en1 = head;	// Creating a en1 pointer (pointing ti the second last node of the list. IT INITIALLY POINTS TO THE FIRST NODE OF THE LIST)
		while(en->link != NULL)		// It executes itself until it reaches the end node	
		{
			en1 = en;	// It is used to reach to the next node
			en = en->link;	// By updating through link part
		}
		en1->link = NULL;	// Assigning null to the link part of the second last node
		free(en);		// It frees the memory
		i--;
		if(i == 0)
			head = NULL;
	}
}




struct node* del_pos(int pos)	// To Delete node at Specific Position specified in the List
{
	int c  =  pos-1;
	struct node *del1 = head;	// Creating del1 pointer
	struct node *del2 = head;	// Creating del2 pointer
	while(c)
	{	
		del1 = del2;
		del2 = del2->link;	// It moves to the next node in the List
		c--;
	}
	if(pos == 1)
		del_begin();	// Calling del_begin
	else if (pos == i)
	{
		del_end();	// Calling del_end 
	}
	else if(pos>i)
		printf("\nInvalid position\n");
	else 
	{
		del1->link = del2->link;	// Updating the link part of the del2 pointer eith the link part of the del2 pointer 
		free(del2);		// It frees the memory
		del2 = NULL;		// Assigning 'NULL' to del2 pointer
		i--;
	}	
}

