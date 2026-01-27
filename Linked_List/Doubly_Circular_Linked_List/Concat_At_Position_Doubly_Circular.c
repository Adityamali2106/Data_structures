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
int DeleteFirst(struct node **,struct node **);
int DeleteLast(struct node **,struct node **);
int DeleteAtPosition(struct node **,struct node **, int);
int SearchFirstOccurrence(struct node *,struct node *, int);
int SearchLastOccurrence(struct node *,struct node *, int);
int SearchAllOccurrences(struct node *,struct node *, int);
int CountNodes(struct node *,struct node *);
void Display(struct node *,struct node *);
void PhysicalReverse(struct node **,struct node **);
void ReverseDisplay(struct node *,struct node *);
void ConcatList(struct node **,struct node **,struct node **,struct node **);
void ConcatAtPosition(struct node **, struct node **,struct node **,struct node **, int);
void DeleteAll(struct node **,struct node **);

int main(void)
{
	struct node *pFirst = NULL;
	struct node *pLast1 = NULL;
	struct node *pSecond = NULL;
	struct node *pLast2 = NULL;

	Display(pFirst,pLast1);

	InsertFirst(&pFirst,&pLast1, 30);
	InsertFirst(&pFirst,&pLast1, 20);
	InsertFirst(&pFirst,&pLast1, 10);

    InsertLast(&pSecond,&pLast2, 100);
	InsertLast(&pSecond,&pLast2, 200);
	InsertLast(&pSecond,&pLast2, 300);

	Display(pFirst,pLast1);
	Display(pSecond,pLast2);
	ConcatAtPosition(&pFirst,&pLast1,&pSecond,&pLast2,2);
	Display(pFirst,pLast1);
	Display(pSecond,pLast2);

    return 0;
}

void ConcatAtPosition(struct node **ppHead1,struct node **ppTail1, struct node **ppHead2, struct node **ppTail2, int iPos)
{
	int iCount;
	struct node *pTemp1 = NULL;

	iCount = CountNodes(*ppHead1,*ppTail1);

	if (iPos <= 0 || iPos > iCount + 1)
	{
		printf("Position is Invalid\n");
		return;
	}

	if(NULL == *ppHead2)
		return;

	if (NULL == *ppHead1)
	{
		*ppHead1 = *ppHead2;
		*ppHead2 = NULL;
		return;
	}

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

	pTemp1 = *ppHead1;
	iCount = 1;

	while(iCount > iPos -1)
	{
		iCount++;
		pTemp1 = pTemp1 -> pNext;
	}


	(*ppTail2)-> pNext = pTemp1 -> pNext;
	pTemp1 -> pNext -> pPrev = *ppTail2;
	pTemp1 -> pNext = *ppHead2;
	(*ppHead2) -> pPrev = pTemp1;

	*ppHead2 = *ppTail2 = NULL;
}

void ConcatList(struct node **ppHead1,struct node **ppTail1,struct node **ppHead2, struct node **ppTail2)
{
	struct node *pTemp = NULL;

	if (NULL == *ppHead2)
		return;

	if (NULL == *ppHead1)
	{
		*ppHead1 = *ppHead2;
		*ppTail1 = *ppTail2;
		*ppHead2 = *ppTail2 =NULL;
		return;
	}

	(*ppTail1) -> pNext = *ppHead2;
	(*ppHead2) -> pPrev = *ppTail1;
		*ppTail1 = *ppTail2;
	(*ppTail1) -> pNext = *ppHead1;
	(*ppHead1) -> pPrev = *ppTail2;

	*ppHead2 = *ppTail2 = NULL;	
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
