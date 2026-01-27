#include <stdio.h>
#include <malloc.h>

struct node 
{
	struct node *pPrev;
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **, int);
void ConcatList(struct node **, struct node **);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
	struct node *pFirst = NULL;
	struct node *pSecond = NULL;

	InsertFirst(&pFirst,50);
	InsertFirst(&pFirst,40);
	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,10);
	
	Display(pFirst);

	InsertFirst(&pSecond,300);
	InsertFirst(&pSecond,200);
	InsertFirst(&pSecond,100);

	Display(pSecond);

	ConcatList(&pFirst,&pSecond);

	printf("After Concat lists lists are :\n");
	Display(pFirst);
	Display(pSecond);

	if (pFirst != NULL)
	{
		DeleteAll(pFirst);
	}

	if (pSecond != NULL)
	{
		DeleteAll(pSecond);
	}

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

void ConcatList(struct node **ppHead1, struct node ** ppHead2)
{
	struct node *pTemp = NULL;

	if (NULL == *ppHead2)
		return;

	if (NULL == *ppHead1)
	{
		*ppHead1  = *ppHead2;
		*ppHead2 = NULL;
		return;
	}

	pTemp = *ppHead1;

	while(pTemp -> pNext != NULL)
		pTemp = pTemp -> pNext;

	pTemp -> pNext = *ppHead2;
	(*ppHead2) -> pPrev = pTemp;

	*ppHead2 = NULL;
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

