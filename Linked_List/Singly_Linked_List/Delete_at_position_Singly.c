#include <stdio.h>
#include <malloc.h>

struct node
{
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **, int);
void InsertAtPosition(struct node **, int, int);
int DeleteAtPosition(struct node **, int);
int DeleteFirst(struct node **);
int CountNodes(struct node *);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
	struct node *pFirst = NULL;
	int iDelData; 

	InsertFirst(&pFirst, 1);
	Display(pFirst);
	InsertAtPosition(&pFirst, 10,1);
	InsertAtPosition(&pFirst, 20,2);
	
	iDelData = DeleteAtPosition(&pFirst, 2);

	if (iDelData != 1)
		printf("Deleted Data is", iDelData);

	Display(pFirst);

	InsertAtPosition(&pFirst, 30,3);
	InsertAtPosition(&pFirst, 40,2);
	InsertAtPosition(&pFirst, 30,0);
	
	iDelData = DeleteAtPosition(&pFirst, 3);

	if (iDelData != 1)
		printf("Deleted Data is", iDelData);
	
	Display(pFirst);
	InsertAtPosition(&pFirst, 50,1);
	
	iDelData = DeleteAtPosition(&pFirst, 1);

	if (iDelData != 1)
		printf("Deleted Data is", iDelData);
	
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
	struct node *pTemp  = NULL;
	int iCount = CountNodes(*ppHead);

	if(iPos <=  0 || iPos > iCount + 1)
	{
		printf("Position Is Invalid\n");
		return;
	}

	if (1 == iPos)
	{
		InsertFirst(ppHead , iNo);
		return;
	}

	pNewNode = (struct node *) malloc(sizeof(struct node));

	if (NULL == pNewNode)
	{
		printf("Memory Allocation Failed\n");
		return;
	}

	pNewNode -> iData = iNo;

	pTemp = *ppHead;
	iCount = 0;

	while(iCount < iPos -1)
	{
		iCount++;

		pTemp = pTemp -> pNext;
	}

	pNewNode -> pNext = pTemp -> pNext;
	pTemp -> pNext = pNewNode;
}

int DeleteAtPosition(struct node **ppHead, int iPos)
{
	struct node *pTemp1 = NULL;
	struct node *pTemp2 = NULL;
	int iCount = CountNodes(*ppHead);

	if (iPos <=  0 || iPos > iCount)
	{
		printf("Position Is Invalid \n");
		return -1;
	}

	if (1 == iPos)
		return DeleteFirst(ppHead);
	
	pTemp1 = *ppHead;
	iCount = 1;

	while(iCount < iPos -1)
	{
		iCount ++;
		pTemp1 = pTemp1-> pNext;
	}

	pTemp2 = pTemp1 -> pNext;
	pTemp1 -> pNext = pTemp2 -> pNext;

	iCount  = pTemp2 -> iData;

	pTemp2 -> pNext = NULL;
	free(pTemp2);

	pTemp1 = pTemp2 = NULL;

	return iCount;
}

int DeleteFirst(struct node **ppHead)
{
	int iDelData;
	struct node *pTemp = NULL;

	if (NULL == *ppHead)
	{
		return -1;
	}

	pTemp = *ppHead;

	*ppHead = pTemp -> pNext;

	iDelData = pTemp -> iData;

	pTemp -> pNext = NULL;

	free(pTemp);

	pTemp = NULL;

	return iDelData;
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
