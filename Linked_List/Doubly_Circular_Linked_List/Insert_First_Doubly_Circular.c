#include<stdio.h>
#include <malloc.h>

struct node
{
	struct node *pPrev;
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **,struct node **, int);
void Display(struct node *,struct node *);
void DeleteAll(struct node **,struct node **);

int main(void)
{
	int iData;
	struct node *pFirst = NULL;
	struct node *pLast = NULL;

	Display(pFirst,pLast);
	
	InsertFirst(&pFirst,&pLast, 10);
	InsertFirst(&pFirst,&pLast, 20);
	InsertFirst(&pFirst,&pLast, 30);

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
