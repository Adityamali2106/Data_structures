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
//  Date            : 08/01/2026
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

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Input           : Address of first pointer
//  Output          : Nothing
//  Description     : Used to Display Linked list
//  Author          : Aditya Vijay Mali
//  Date            : 08/01/2026
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
//  Function Name   : PhysicalReverse
//  Input           : Address of first pointer 
//  Output          : Nothing
//  Description     : Used to reverse the linked list physically
//  Author          : Aditya Vijay Mali
//  Date            : 08/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

void PhysicalReverse(PPNODE first)
{
	PNODE Next = NULL;
	PNODE Current = *first;
	PNODE Prev = NULL;

	while(Current != NULL)
	{
		Next = Current -> next;
		Current -> next = Prev;
		Prev = Current;
		Current = Next;
	}

	*first = Prev;
}	// End of PhysicalReverse

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DisplayReverse
//  Input           : Address of first pointer,data tobe check less 
//  Output          : Nothing
//  Description     : Used to Display Less than nodes given data from linked list
//  Author          : Aditya Vijay Mali
//  Date            : 08/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

void ReverseDisplay(PNODE first)
{
	if (NULL == first)
	{
		printf("List is Empty\n");
		return;
	}

	PhysicalReverse(&first);
	Display(first);
	PhysicalReverse(&first);
}	// End of DisplayReverse

///////////////////////////////////////////////////////////////////////////////////
//
//  Entry point function for Application
//
///////////////////////////////////////////////////////////////////////////////////

int main()
{
	struct node *head = NULL;
	int iRet = 0;

	InsertFirst(&head,12);
	InsertFirst(&head,52);
	InsertFirst(&head,6);
	InsertFirst(&head,16);
	InsertFirst(&head,10);
	InsertFirst(&head,65);

	Display(head);

	ReverseDisplay(head);

	Display(head);

	return 0;
}	// End of main
