///////////////////////////////////////////////////////////////////////////////////
//
//		Required Header Files
//
///////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////////
//
//		structure Declaration for linked list
//
///////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
struct node
{
	int data;
	struct node * next;
};

/*--------------------------------------------------------------------------------
        Old Name                    New Name
----------------------------------------------------------------------------------
        struct Node                 NODE
        struct Node *               PNODE
        struct Node **              PPNODE
----------------------------------------------------------------------------------*/

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertFirst
//  Input           : Data of Node
//  Output          : Nothing
//  Description     : Used to insert node at first position
//  Author          : Aditya Vijay Mali
//  Date            : 09/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first,int no)
{
	PNODE newn = NULL;

	newn = (PNODE) malloc(sizeof(NODE));

	newn -> data = no;
	newn -> next = NULL;

	newn -> next = *first;
	*first = newn;
}	// End of InsertFirst

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Difference
//  Input           : Address of head pointer
//  Output          : Difference
//  Description     : Used to Calculate te difference bvetween minimum and maximum element
//  Author          : Aditya Vijay Mali
//  Date            : 09/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

int Difference(PNODE first)
{
	int iMin = first -> data;
	int iMax = first -> data - first -> data;
	while(first != NULL)
	{
		if (iMin > first ->data)
		{
			iMin = first -> data;
		}
		if (iMax < first -> data)
		{
			iMax = first -> data;			 
		}
		first = first -> next;
	}

	return (iMax - iMin);
}	// End of Difference

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Input           : Address of first pointer
//  Output          : Nothing
//  Description     : Used to Display Linked list
//  Author          : Aditya Vijay Mali
//  Date            : 09/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
	if(first == NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}

	while(first != NULL)
	{
		printf("| %d | ->", first -> data);
		first = first -> next;
	}

	printf(" NULL\n");
}	// End of Display

///////////////////////////////////////////////////////////////////////////////////
//
//  Entry point function for Application
//
///////////////////////////////////////////////////////////////////////////////////

int main()
{
	struct node *head = NULL;
	int iRet = 0;

	InsertFirst(&head,17);
	InsertFirst(&head,52);
	InsertFirst(&head,9);
	InsertFirst(&head,16);
	InsertFirst(&head,11);
	InsertFirst(&head,62);

	Display(head);

	iRet = Difference(head);

	printf("Difference between minimum and MAximum element is : %d \n", iRet);

	return 0;
}	// End of main
