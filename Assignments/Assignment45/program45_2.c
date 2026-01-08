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
//  Function Name   : FirstOccur
//  Input           : Address of first pointer,data tobe check 
//  Output          : Integer : count of First Occurrence of given data 
//  Description     : Used to find the First Occurrence of a data in linked list
//  Author          : Aditya Vijay Mali
//  Date            : 08/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

int FirstOccur(PNODE first, int no)
{
	int iCount = 0;

	while(first != NULL)
	{
		iCount++;
		if (first -> data == no)
		{
			break;
		}
		first =first -> next;
	}

	return iCount;
}

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

	InsertFirst(&head,12);
	InsertFirst(&head,52);
	InsertFirst(&head,12);
	InsertFirst(&head,16);
	InsertFirst(&head,10);
	InsertFirst(&head,12);

	Display(head);

	iRet = FirstOccur(head,12);

	printf("First Occerrence of : %d data At found at : %d position \n",12, iRet);

	return 0;
}	// End of main
