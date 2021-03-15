#include<stdio.h>
#include<stdlib.h>
#include "../inc/applinkedlist.h"
void main()
{
	int n, data,pos;
	char choice;
	head = NULL;
	while(choice != '0')
	{
		printf("============================================\n");
		printf("       SINGLY LINKED LIST PROGRAM\n");
		printf("============================================\n");
		printf("1. Create List\n");
		printf("2. Display list\n");
		printf("3. Add node - from begining\n");
		printf("4. ADD node - from end\n");
		printf("5. ADD node - from specific position\n");
		printf("6. Delete node - from beginning\n");
		printf("7. Delete node - from end\n");
		printf("8. Delete node - from specific position\n");
		printf("0. Exit\n");
		printf("--------------------------------------------\n");
		printf("Enter your choice : ");

		scanf(" %c", &choice);

		switch(choice)
		{
			case '1':	// Create List
				printf("Enter the total number of nodes in list: ");
				scanf("%d", &n);
				createlist(n);
		       		break;
			case '2':	// Display List
		                print_node(head);
		                break;
			case '3':	// Add node - from begining
				printf("\nEnter the data\n");
				scanf("%d",&data);
				add_begin(data);
				break;
			case '4':	// ADD node - from end
				printf("\nEnter the data\n");
			        add_node(data);
				break;
			case '5':	// ADD node - from specific position
			        printf("Enter the position where you want to add a node: ");
		                scanf("%d", &pos);
			        pos_node(head,data,pos);
				break;
			case '6':	// Delete node - from beginning
		        	del_begin();
		        	break;
			case '7':	// Delete node - from end
		        	del_end();
		        	break;
			case '8':	//Delete node - from specific position
				printf("Enter the node position which you want to delete: ");
				scanf("%d", &n);
				del_pos(n);
		        	break;
			case '0':	// Exit
		        	break;
			default:
		        	printf("Error!!! Invalid choice. Please choose between 0-8");
		}

		printf("\n\n");
	}
}
