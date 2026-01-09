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
//  Function Name   : CountTwoDigit
//  Input           : Address of head pointer
//  Output          : Integer 
//  Description     : Used to count the number of element that have two digits
//  Author          : Aditya Vijay Mali
//  Date            : 09/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

int CountTwoDigit(PNODE first)
{
	int iCount = 0;
	int iDigit = 0;
	int iTemp = 0;

	while(first != NULL)
	{
		iTemp = first -> data;
		iDigit = 0;
		while(iTemp != 0)
		{
			iDigit++;
			iTemp = iTemp / 10;
		}
		if (iDigit == 2)
		{
			iCount++;
		}
		first = first -> next;
	}
	return iCount;
}	// End of CountTwoDigit

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

	InsertFirst(&head,162);
	InsertFirst(&head,52);
	InsertFirst(&head,-6);
	InsertFirst(&head,-16);
	InsertFirst(&head,10);
	InsertFirst(&head,65);

	Display(head);

	iRet = CountTwoDigit(head);

	printf("Total elements having two digits are : %d \n", iRet);
	return 0;
}	// End of main
