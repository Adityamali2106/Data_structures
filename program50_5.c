///////////////////////////////////////////////////////////////////////////////////
//
//		Required Header Files
//
///////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
//  Function Name   : Count
//  Input           : Address of first pointer
//  Output          : Integer(Count of Nodes)
//  Description     : Used to count nodes present in linked list
//  Author          : Aditya Vijay Mali
//  Date            : 08/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

int Count(PNODE first)
{
	int iCount = 0;

	while(first != NULL)
	{
		iCount++;
		first = first -> next;
	}

	return iCount;
}	// End of Count

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DisplayAtPos
//  Input           : Address of head pointer
//  Output          : Boolean
//  Description     : Used to Count Nodes at Nth Position
//  Author          : Aditya Vijay Mali
//  Date            : 08/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

void DisplayAtPos(PNODE first, int pos)
{
	int iCount = 0;
	iCount = Count(first);

	if (pos < 1 && pos > iCount)
	{
		printf("Position is invalid \n");
		return;
	}

	for (iCount = 1; iCount < pos; iCount++)
	{
		first = first -> next;
	}

	printf("%d node value is : %d \n", pos, first -> data);
}	// End of DisplayAtPos

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
//  Entry point function for Application
//
///////////////////////////////////////////////////////////////////////////////////

int main()
{
	struct node *head = NULL;
	bool bRet = false;

	InsertFirst(&head,17);
	InsertFirst(&head,52);
	InsertFirst(&head,-9);
	InsertFirst(&head,-16);
	InsertFirst(&head,11);
	InsertFirst(&head,60);

	Display(head);

	DisplayAtPos(head,3);

	return 0;
}	// End of main
