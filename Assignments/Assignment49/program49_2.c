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
//  Function Name   : CheckAllPositive
//  Input           : Address of head pointer
//  Output          : Boolen
//  Description     : Used to Check whether All elements are Positive
//  Author          : Aditya Vijay Mali
//  Date            : 09/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

bool CheckAllPositive(PNODE first)
{
	bool bFlag = true;
	while(first != NULL)
	{
		if (first -> data < 1)
		{
			bFlag = false;			 
		}
		first = first -> next;
	}

	return bFlag;
}	// End of CheckAllPositive

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
	bool bRet = 0;

	InsertFirst(&head,17);
	InsertFirst(&head,52);
	InsertFirst(&head,9);
	InsertFirst(&head,16);
	InsertFirst(&head,11);
	InsertFirst(&head,62);

	Display(head);

	bRet = CheckAllPositive(head);

	if (bRet == true)
	{
		printf("All elements are positive \n");
	}
	else
	{
		printf("All elements are not positive \n");
	}
	return 0;
}	// End of main
