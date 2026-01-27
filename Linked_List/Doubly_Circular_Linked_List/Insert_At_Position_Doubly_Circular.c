#include<stdio.h>
#include <malloc.h>

struct node
{
	struct node *pPrev;
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **,struct node **, int);
void InsertLast(struct node **,struct node **, int);
void InsertAtPosition(struct node **,struct node **, int, int);
int CountNodes(struct node *,struct node *);
void Display(struct node *,struct node *);
void DeleteAll(struct node **,struct node **);

int main(void)
{
	int iData;
	struct node *pFirst = NULL;
	struct node *pLast = NULL;

    InsertFirst(&pFirst,&pLast, 1);
	Display(pFirst,pLast);
	InsertAtPosition(&pFirst,&pLast, 10,1);
	Display(pFirst,pLast);
	InsertAtPosition(&pFirst,&pLast, 20,2);
	Display(pFirst,pLast);
	InsertAtPosition(&pFirst,&pLast, 30,3);
	Display(pFirst,pLast);
	InsertAtPosition(&pFirst,&pLast, 40,2);
	Display(pFirst,pLast);
	InsertAtPosition(&pFirst,&pLast, 30,0);
	Display(pFirst,pLast);
	InsertAtPosition(&pFirst,&pLast, 50,1);

	Display(pFirst,pLast);
	InsertAtPosition(&pFirst,&pLast, 30,3);
	printf("Count IS : %d",CountNodes(pFirst,pLast));
	Display(pFirst,pLast);

	DeleteAll(&pFirst,&pLast);
	Display(pFirst,pLast);
	
    return 0;
}

void InsertFirst(struct node **ppHead,struct node **ppTail, int iNo)
{
	struct node *pNewNode = NULL;

	pNewNode = (struct node *) malloc (sizeof(struct node));

	if (NULL == pNewNode)
	{
		printf("Memory Allocation FAILED\n");
		return;
	}

	pNewNode -> iData = iNo;
	pNewNode -> pPrev = *ppTail;

	if(NULL == *ppHead)
	{
		*ppTail = pNewNode;
	}
	else
	{
		pNewNode -> pNext = *ppHead;
		(*ppHead) -> pPrev = pNewNode;
	}

	*ppHead = pNewNode;
	(*ppTail) -> pNext = *ppHead;
	(*ppHead) -> pPrev = *ppTail;
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

void InsertAtPosition(struct node **ppHead,struct node **ppTail, int iNo , int iPos)
{
	int iCount;
	struct node *pNewNode = NULL;
	struct node *pTemp = NULL;

	iCount = CountNodes(*ppHead, *ppTail);

	if (iPos <= 0 || iPos > iCount + 1)
	{
		printf("Position Is Invalid\n");
		return;
	}

	if (1 == iPos)
	{
		InsertFirst(ppHead,ppTail, iNo);
		return;
	}

	pNewNode = (struct node *) malloc (sizeof(struct node));
	if (NULL == pNewNode)
	{
		printf("Memory Allocation FAILED\n");
		return;
	}

	pNewNode -> iData = iNo;

	pTemp = *ppHead;
	iCount = 0;

	while(iCount < iPos)
	{
		iCount++;
		pTemp = pTemp -> pNext;
	}

	pNewNode -> pNext = pTemp -> pNext;
	pTemp -> pNext -> pPrev = pNewNode;
	pTemp -> pNext = pNewNode;
	pNewNode -> pPrev = pTemp;
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
