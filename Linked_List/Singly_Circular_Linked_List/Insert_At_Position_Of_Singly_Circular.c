#include <stdio.h>
#include <malloc.h>

struct node
{
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **,struct node **, int);
void InsertAtPosition(struct node **,struct node **, int, int);
int CountNodes(struct node *,struct node *);
void Display(struct node *,struct node *);
void DeleteAll(struct node **,struct node **);

int main(void)
{
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

	pNewNode = (struct node *) malloc(sizeof(struct node));
	if (NULL == pNewNode)
	{
		printf("Memory Allocation Failed\n");
		return;
	}

	pNewNode -> iData = iNo;

	if (NULL == *ppHead)
	{
		*ppHead = pNewNode;
		*ppTail = pNewNode;
		(*ppTail) -> pNext = pNewNode;
		return;
	}

	pNewNode -> pNext = *ppHead;
	(*ppTail) -> pNext = pNewNode;

	*ppHead = pNewNode;	
}

void InsertAtPosition(struct node **ppHead,struct node **ppTail, int iNo, int iPos)
{
	struct node *pNewNode = NULL;
	struct node *pTemp = NULL;
	int iCount;

	iCount = CountNodes(*ppHead,*ppTail);

	if (iPos <= 0 || iPos > iCount + 1)
	{
		printf("Position Is invalid\n");
		return;
	}

	if(iPos == 1)
	{
		InsertFirst(ppHead,ppTail, iNo);
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
	if(NULL == pHead)
	{
		printf("List is Empty\n");
		return;
	}

	do
	{
		printf("|%d|->", pHead -> iData);
		pHead = pHead -> pNext;
	}while(pHead != pTail -> pNext);

	printf("\n");
}

void DeleteAll(struct node **ppHead, struct node **ppTail)
{
	struct node *pTemp = NULL;
	(*ppTail) -> pNext = NULL;

	while(*ppHead != NULL)
	{
		pTemp = *ppHead;
		*ppHead = pTemp -> pNext;
		pTemp -> pNext = NULL;
		free(pTemp);
	}

	pTemp = NULL;

}
