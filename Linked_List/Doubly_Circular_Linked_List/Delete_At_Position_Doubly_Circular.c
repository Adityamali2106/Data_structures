#include<stdio.h>
#include <malloc.h>

struct node
{
	struct node *pPrev;
	int iData;
	struct node *pNext;
};

void InsertLast(struct node **,struct node **, int);
int DeleteAtPosition(struct node **,struct node **, int);
int DeleteFirst(struct node **,struct node **);
int DeleteLast(struct node **,struct node **);
int CountNodes(struct node *,struct node *);
void Display(struct node *,struct node *);
void DeleteAll(struct node **,struct node **);

int main(void)
{
	int iData;
	struct node *pFirst = NULL;
	struct node *pLast = NULL;

    InsertLast(&pFirst,&pLast, 10);
	InsertLast(&pFirst,&pLast, 20);
	InsertLast(&pFirst,&pLast, 30);
	InsertLast(&pFirst,&pLast, 40);

	Display(pFirst,pLast);

    iData = DeleteAtPosition(&pFirst,&pLast,3);

    printf("Deleted Node is From 3 position is : %d \n",iData);

	Display(pFirst,pLast);
    DeleteAll(&pFirst,&pLast);

    return 0;
}

void InsertLast(struct node **ppHead ,struct node **ppTail, int iNo)
{
	struct node *pNewNode = NULL;

	pNewNode = (struct node *) malloc (sizeof(struct node));

	if (NULL == pNewNode)
	{
		printf("Memory Allocation FAILED\n");
		return;
	}

	pNewNode -> iData = iNo;

	if (NULL == *ppHead)
	{
		*ppHead = pNewNode;
		*ppTail = pNewNode;
		(*ppTail) -> pNext = *ppHead;
		(*ppHead) -> pPrev = *ppTail;
		return;
	}

	(*ppTail) -> pNext = pNewNode;
	pNewNode -> pPrev = *ppTail;
	*ppTail = pNewNode;
	(*ppTail) -> pNext = *ppHead;
	(*ppHead) -> pPrev = *ppTail;
}
int DeleteFirst(struct node **ppHead, struct node **ppTail)
{
	int iDelData;

	if (NULL == *ppHead)
		return -1;

	iDelData = (*ppHead) -> iData;

	if (*ppHead == *ppTail)
	{
		free(*ppHead);
		*ppHead = *ppTail = NULL;
	}	
	else
	{
		*ppHead = (*ppHead) -> pNext;

		(*ppHead) -> pPrev -> pNext = NULL;
		(*ppHead) -> pPrev -> pPrev = NULL;
		free((*ppHead) -> pPrev);

		(*ppTail) -> pNext = *ppHead;
		(*ppHead) -> pPrev = *ppTail;
	}

	return iDelData;
}

int DeleteLast(struct node **ppHead,struct node **ppTail)
{
	int iDelData;

	if (NULL == *ppHead)
		return -1;

	iDelData = (*ppTail) -> iData;
	
	if (*ppHead == *ppTail)
	{
		(*ppTail) -> pNext = NULL;
		free(*ppTail);
		*ppHead = *ppTail = NULL;
		return iDelData;
	}
	
	*ppTail = (*ppTail ) -> pPrev ;
	(*ppTail) -> pNext -> pNext = NULL;
	(*ppTail) -> pNext -> pPrev = NULL;
	free((*ppTail) -> pNext);
	(*ppTail) -> pNext = *ppHead;
	(*ppHead) -> pPrev = *ppTail;

	return iDelData;
}

int DeleteAtPosition(struct node **ppHead,struct node **ppTail, int iPos)
{
	int iCount;
	struct node *pTemp = NULL;

	iCount = CountNodes(*ppHead, *ppTail);

	if (iPos <= 0 || iPos > iCount)
	{
		printf("Position is Invalid");
		return -1;
	}

	if (1 == iPos)
		return DeleteFirst(ppHead,ppTail);

	if (iPos == iCount)
		return DeleteLast(ppHead, ppTail);
	
	pTemp = *ppHead;
	iCount = 1;

	while(iCount < iPos)
	{
		iCount++;
		pTemp = pTemp -> pNext;
	}	

	iCount = pTemp -> iData;
	pTemp -> pPrev -> pNext = pTemp -> pNext;
	pTemp -> pNext ->pPrev = pTemp -> pPrev;

	pTemp -> pNext = pTemp -> pPrev = NULL;
	free(pTemp);

	pTemp = NULL;

	return iCount;
}

int CountNodes(struct node *pHead,struct node *pTail)
{
	int iCount = 0;

	if(NULL == pHead)
		return 0;

	do
	{
		iCount++;
		pHead = pHead -> pNext;
	}while(pHead != pTail -> pNext);

	return iCount;
}

void Display(struct node *pHead,struct node *pTail)
{
	if (NULL == pHead)
	{
		printf("List is Empty\n");
		return;
	}

	do
	{
		printf("|%d|->", pHead -> iData);
		pHead = pHead-> pNext;
	}while(pHead != pTail -> pNext);
	printf("\n");
}

void DeleteAll(struct node **ppHead, struct node **ppTail)
{
	struct node *pTemp = NULL;
	(*ppTail) ->pNext = NULL;

	while(*ppHead != NULL)
	{
		pTemp = *ppHead;
		*ppHead = pTemp -> pNext;
		pTemp -> pNext = NULL;
		pTemp -> pPrev = NULL;
		free(pTemp);
	}

	pTemp = NULL;
}
