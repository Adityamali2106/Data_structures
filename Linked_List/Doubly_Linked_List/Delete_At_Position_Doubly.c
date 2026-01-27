#include <stdio.h>
#include <malloc.h>

struct node 
{
	struct node *pPrev;
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **, int);
int DeleteFirst(struct node **);
int DeleteAtPosition(struct node **, int);
int DeleteLast(struct node **);
int CountNodes(struct node *);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
	struct node *pFirst = NULL;
	int iDelData;

	InsertFirst(&pFirst,50);
	InsertFirst(&pFirst,40);
	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,10);
	
	Display(pFirst);

	iDelData = DeleteAtPosition(&pFirst, 2);
	if (iDelData != -1)
		printf("Deleted Data Is : %d \n", iDelData);

	iDelData = DeleteAtPosition(&pFirst, 1);
	if (iDelData != -1)
		printf("Deleted Data Is : %d \n", iDelData);

	iDelData = DeleteAtPosition(&pFirst, 3);
	if (iDelData != -1)
		printf("Deleted Data Is : %d \n", iDelData);

	Display(pFirst);
	DeleteAll(&pFirst);
	return 0;
}

void InsertFirst(struct node **ppHead, int iNo)
{
	struct node *pNewNode = NULL;
	pNewNode = (struct node *) malloc (sizeof(struct node));

	if (NULL == pNewNode)
	{
		printf("MEmory Allocation Failed\n");
		return;
	}

	pNewNode -> iData = iNo;
	pNewNode -> pPrev = NULL;

	if (NULL == *ppHead)
	{
		pNewNode -> pNext = NULL;
	}
	else
	{
		pNewNode -> pNext = *ppHead;
		(*ppHead) -> pPrev = pNewNode;
	}

	*ppHead = pNewNode;
}

int DeleteAtPosition(struct node **ppHead, int iPos)
{
	int iCount;
	struct node *pTemp = NULL;

	iCount = CountNodes(*ppHead);

	if (iPos <= 0 || iPos > iCount)
	{
		printf("Position is Invalid\n");
		return -1;
	}

	if (1 == iPos)
		return DeleteFirst(ppHead);

	if (iPos == iCount)
		return DeleteLast(ppHead);
	
	pTemp = *ppHead;
	iCount = 1;

	while( iCount != iPos)
	{
		iCount++;
		pTemp = pTemp -> pNext;
	}

	iCount = pTemp -> iData;

	pTemp -> pPrev -> pNext = pTemp -> pNext;
	pTemp -> pNext -> pPrev = pTemp -> pPrev;

	pTemp -> pNext = NULL;
	pTemp -> pNext = NULL;

	free(pTemp);
	pTemp = NULL;
	return iCount;
}

int DeleteLast(struct node **ppHead)
{
	struct node *pTemp = NULL;
	int iDelData;

	if (NULL == *ppHead)
		return -1;

	if ((*ppHead) -> pNext == NULL)
	{
		iDelData = ((*ppHead) -> iData);
		free(*ppHead);
		*ppHead = NULL;
		return iDelData;
	}

	pTemp = *ppHead;

	while(pTemp -> pNext != NULL)
		pTemp = pTemp -> pNext;

	iDelData = pTemp -> iData;

	pTemp -> pPrev -> pNext = NULL;
	pTemp -> pPrev = NULL;
	free(pTemp);

	return iDelData;
}

int DeleteFirst(struct node **ppHead)
{
	int iDelData;

	if (NULL == *ppHead)
		return -1;

	iDelData = (*ppHead) -> iData;

	if (NULL == (*ppHead)-> pNext )
	{
		free(*ppHead);

		*ppHead = NULL;		
	}
	else
	{
		*ppHead = (*ppHead) -> pNext;

		(*ppHead) -> pPrev -> pNext = NULL;
		free((*ppHead)-> pPrev);

		(*ppHead)-> pPrev = NULL;
	}

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
		*ppHead = pTemp -> pNext;
		pTemp -> pNext = NULL;
		pTemp -> pPrev = NULL;
		free(pTemp);
	}
}
