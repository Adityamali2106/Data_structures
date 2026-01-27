#include <stdio.h>
#include <malloc.h>

struct node
{
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **, int);
void InsertAtPosition(struct node **, int, int);
int CountNodes(struct node *);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
	struct node *pFirst = NULL;

	InsertFirst(&pFirst, 1);
	Display(pFirst);
	InsertAtPosition(&pFirst, 10,1);
	Display(pFirst);
	InsertAtPosition(&pFirst, 20,2);
	Display(pFirst);
	InsertAtPosition(&pFirst, 30,3);
	Display(pFirst);
	InsertAtPosition(&pFirst, 40,2);
	Display(pFirst);
	InsertAtPosition(&pFirst, 30,0);
	Display(pFirst);
	InsertAtPosition(&pFirst, 50,1);

	Display(pFirst);

	DeleteAll(&pFirst);
	Display(pFirst);
	
	return 0;
}

void InsertFirst(struct node **ppHead, int iNo)
{
	struct node *pNewNode = NULL;

	pNewNode = (struct node *) malloc(sizeof(struct node));
	if (NULL == pNewNode)
	{
		printf("Memory Allocation Failed\n");
		return;
	}

	pNewNode -> iData = iNo;

	pNewNode -> pNext = *ppHead;

	*ppHead = pNewNode;	
}

void InsertAtPosition(struct node **ppHead, int iNo, int iPos)
{
	struct node *pNewNode = NULL;
	struct node *pTemp = NULL;
	int iCount;

	iCount = CountNodes(*ppHead);

	if (iPos <= 0 || iPos > iCount + 1)
	{
		printf("Position Is invalid\n");
		return;
	}

	if(iPos == 1)
	{
		InsertFirst(ppHead, iNo);
		return;
	}

	pNewNode = (struct node *) malloc (sizeof(struct node));
	if (NULL == *ppHead)
	{
		printf("Memory Allocation Failed \n");
		return;
	}

	pNewNode -> iData = iNo;

	pTemp = *ppHead;
	iCount = 1;

	while(iCount < iPos -1)
	{
		iCount ++;
		pTemp = pTemp -> pNext;
	}

	pNewNode -> pNext = pTemp -> pNext;
	pTemp -> pNext = pNewNode;
}

int CountNodes(struct node *pHead)
{
	int iCount = 0;
	while(pHead != NULL)
	{
		iCount ++;
		pHead = pHead -> pNext;
	}

	return iCount;
}

void Display(struct node *pHead)
{
	if (NULL == pHead)
	{
		printf("List is Empty\n");
		return;
	}

	while(pHead != NULL)
	{
		printf("|%d|-> ", pHead -> iData);
		pHead = pHead -> pNext;
	}
	printf("\n");
}

void DeleteAll(struct node **ppHead)
{
	struct node *pTemp = NULL;

	while(*ppHead != NULL)
	{
		pTemp = *ppHead;
		*ppHead  = pTemp -> pNext;
		pTemp -> pNext = NULL;
		free(pTemp);
	}

	pTemp = NULL;
}

