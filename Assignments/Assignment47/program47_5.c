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
//  Function Name   : CountPrime
//  Input           : Address of head pointer
//  Output          : Count of prime number 
//  Description     : Used to Count prime elements
//  Author          : Aditya Vijay Mali
//  Date            : 08/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

int CountPrime(PNODE first)
{
	int iCnt = 0;
	int flag = 0;
	int iCount = 0;
	while(first != NULL)
	{
		for (iCnt = 1, flag = 0; iCnt <= ((first-> data)%2); iCnt++)
		{
			//printf("iCnt %d  ",iCnt);
			if (((first-> data) % iCnt) == 0)
			{
				flag++;
			}
		}

		if (flag == 1)
		{
			iCount++;
		}
		first = first -> next;
	}

	return iCount;
}	// End of CountPrime

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
	InsertFirst(&head,-6);
	InsertFirst(&head,-16);
	InsertFirst(&head,13);
	InsertFirst(&head,67);

	Display(head);

	iRet = CountPrime(head);

	printf("Prime elements in Linked list are : %d\n", iRet);
	return 0;
}	// End of main
