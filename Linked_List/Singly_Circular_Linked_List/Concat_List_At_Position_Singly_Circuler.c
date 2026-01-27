#include<stdio.h>
#include <malloc.h>

struct node
{
	int iData;
	struct node *pNext;
};

void InsertLast(struct node **,struct node **, int);
int CountNodes(struct node *,struct node *);
void Display(struct node *,struct node *);
void ConcatList(struct node **,struct node **,struct node **,struct node **);
void ConcatAtPosition(struct node **, struct node **,struct node **,struct node **, int);
void DeleteAll(struct node **,struct node **);

int main(void)
{
	int iData;
	struct node *pFirst = NULL;
	struct node *pLast = NULL;
	struct node *pSecond = NULL;
	struct node *pLast2 = NULL;


   	InsertLast(&pFirst,&pLast, 10);
	InsertLast(&pFirst,&pLast, 20);
	InsertLast(&pFirst,&pLast, 50);
	InsertLast(&pFirst,&pLast, 60);

    InsertLast(&pSecond,&pLast2, 1000);
	InsertLast(&pSecond,&pLast2, 1000);
	InsertLast(&pSecond,&pLast2, 2000);
	InsertLast(&pSecond,&pLast2, 3000);	

	Display(pFirst,pLast);
	Display(pSecond,pLast2);
	ConcatAtPosition(&pFirst,&pLast,&pSecond,&pLast2, 3);
	Display(pFirst,pLast);
	Display(pSecond,pLast2);

	if (pFirst != NULL)
	{
		DeleteAll(&pFirst,&pLast);
		pFirst = NULL;
	}

	if (pSecond != NULL)
	{
		DeleteAll(&pSecond,&pLast);
		pSecond = NULL;
	}

	return 0;
}

void ConcatList(struct node **ppHead1,struct node **ppTail1,struct node **ppHead2,struct node **ppTail2)
{
	if(NULL == *ppHead2)
		return;

	if(NULL == *ppHead1)
	{
		*ppHead1 = *ppHead2;
		*ppTail1 = *ppTail2;
	}
	else
	{		
		(*ppTail1) -> pNext = *ppHead2;
		*ppTail1 = *ppTail2;
		(*ppTail2) -> pNext = *ppHead1;
	}

	*ppHead2 = *ppTail2 = NULL;
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppTail1,struct node **ppHead2,struct node **ppTail2, int iPos)
{
	int iCount;
	struct node *pTemp = NULL;

	iCount = CountNodes(*ppHead1, *ppTail1);

	if (iPos <= 0 || iPos > iCount + 1)
	{
		printf("Position Is Invalid \n");
		return;
	}

	if (NULL == *ppHead2)
		return;

	if (1 == iPos)
	{
		ConcatList(ppHead2, ppTail2, ppHead1, ppTail1);
		*ppHead1 = *ppHead2;
		*ppTail1 = *ppTail2;
		*ppHead2 = *ppTail2 = NULL;
		return;
	}

	if (iPos == iCount + 1)
	{
		ConcatList(ppHead1, ppTail1, ppHead2, ppTail2);
		return;
	}

	pTemp = *ppHead1;
	iCount = 0;

	while(iCount > iPos)
	{
		iCount++;
		pTemp = pTemp -> pNext;
	}

	(*ppTail2) -> pNext = pTemp -> pNext;
	pTemp -> pNext = *ppHead2;

	*ppHead2 = *ppTail2 = NULL;
}

void InsertLast(struct node **ppHead, struct node **ppTail, int iNo)
{
	struct node *pNewNode = NULL;

	pNewNode = (struct node *) malloc (sizeof(struct node));

	if (NULL == pNewNode)
	{
		printf("Memory Allocation FAILED\n");
		return;
	}

	pNewNode -> iData = iNo;

	if(NULL == *ppHead)
	{
		*ppHead = pNewNode;
		*ppTail = pNewNode;
		(*ppTail)->pNext = pNewNode;
		return;
	}

	(*ppTail) -> pNext = pNewNode;
	*ppTail = pNewNode;
	(*ppTail)->pNext = *ppHead;
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

void DeleteAll(struct node **ppHead, struct node **ppTail)
{
	struct node *pTemp = NULL;
	(*ppTail) ->pNext = NULL;

	while(*ppHead != NULL)
	{
		pTemp = *ppHead;
		*ppHead = pTemp -> pNext;
		pTemp -> pNext = NULL;
		free(pTemp);
	}

	pTemp = NULL;
}

