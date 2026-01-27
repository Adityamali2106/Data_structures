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
void Display(struct node *,struct node *);
void ConcatList(struct node **,struct node **,struct node **,struct node **);
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
	ConcatList(&pFirst,&pLast1,&pSecond,&pLast2);
	Display(pFirst,pLast1);
	Display(pSecond,pLast2);

    return 0;
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

