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

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DisplayGreaterThanAvg
//  Input           : Address of head pointer
//  Output          : Nothing
//  Description     : Used to Display Elements Greater Than Average
//  Author          : Aditya Vijay Mali
//  Date            : 08/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

void DisplayGreaterThanAvg(PNODE first)
{
	PNODE temp = first;
	int iAns = 0;
	int iCount = 0;
	int iAvg = 0;

	while(temp != NULL)
	{
		iCount++;
		iAns = (iAns + temp -> data);
		temp = temp -> next;
	}

	iAvg = iAns / iCount;
	printf("Greater Than Average Elements are :\t ");

	while(first != NULL)
	{
		if (first -> data > iAvg)
		{
			printf("| %d | ->", first -> data);
		}
		first = first -> next;
	}

	printf(" NULL\n");
}	// End of DisplayGreaterThanAvg

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
	int iRet = 0;

	InsertFirst(&head,17);
	InsertFirst(&head,52);
	InsertFirst(&head,9);
	InsertFirst(&head,16);
	InsertFirst(&head,11);
	InsertFirst(&head,60);

	Display(head);

	DisplayGreaterThanAvg(head);

	Display(head);
	return 0;
}	// End of main
