#include <stdio.h>
#include <malloc.h>

struct node 
{
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **, int);
void ConcatList(struct node **, struct node **);
void ConcatAtPosition(struct node **, struct node **, int);
void Display(struct node *);
void DeleteAll(struct node **);
int CountNodes(struct node *);

int main(void)
{
	struct node *pFirst = NULL;
	struct node *pSecound = NULL;
	InsertFirst(&pFirst,50);
	InsertFirst(&pFirst,40);
	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,10);

	Display(pFirst);


	InsertFirst(&pSecound, 400);
	InsertFirst(&pSecound, 300);
	InsertFirst(&pSecound, 200);
	InsertFirst(&pSecound, 100);

	Display(pSecound);

	printf("Lists brfore Concat\n");
	Display(pFirst);
	Display(pSecound);

	ConcatAtPosition(&pFirst, &pSecound,2);

	InsertFirst(&pSecound, 3000);
	InsertFirst(&pSecound, 2000);
	InsertFirst(&pSecound, 1000);

	printf("After Concat lists Are \n");

	Display(pFirst);
	Display(pSecound);

	ConcatAtPosition(&pFirst, &pSecound,13);

	InsertFirst(&pSecound, 30000);
	InsertFirst(&pSecound, 20000);
	InsertFirst(&pSecound, 10000);

	printf("After Concat lists Are \n");

	Display(pFirst);
	Display(pSecound);

	ConcatAtPosition(&pFirst, &pSecound,1);

	ConcatAtPosition(&pFirst, &pSecound,0);

	printf("After Concat lists Are \n");

	Display(pFirst);
	Display(pSecound);


	DeleteAll(&pFirst);	
	return 0;
}

void InsertFirst(struct node **ppHead, int iNo)
{
	struct node *pNewNode = NULL;

	pNewNode = (struct node *) malloc (sizeof(struct node));

	if (NULL == pNewNode)
	{
		printf("Memory Allocation Failed\n");
		return;
	}

	pNewNode -> iData = iNo;
	
	pNewNode -> pNext = *ppHead;

	*ppHead = pNewNode;
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
	int iCount;
	struct node *pTemp1 = NULL;
	struct node *pTemp2 = NULL;

	iCount = CountNodes(*ppHead1);

	if(iPos <= 0 || iPos > iCount + 1)
	{
		printf("PoSition is Invalid\n");
		return;
	}

	if (NULL == *ppHead2)
		return;

	if (NULL == *ppHead1)
	{
		*ppHead1 = *ppHead2;
		*ppHead2 = NULL;
		return;
	}

	if (1 == iPos)
	{
		ConcatList(ppHead2, ppHead1);
		*ppHead1 = *ppHead2;
		*ppHead2 = NULL;
		return;
	}

	// if (iPos == iCount + 1)
	// {
	// 	ConcatList(ppHead1,ppHead2);
	// 	return;
	// }

	pTemp1 = *ppHead1;
	iCount = 1;
	while(iCount > iPos - 1)
	{
		iCount++;
		pTemp1 = pTemp1 -> pNext;
	}

	pTemp2 = *ppHead2;

	while(pTemp2 -> pNext != NULL)
		pTemp2 = pTemp2 -> pNext;

	pTemp2 -> pNext = pTemp1 -> pNext;

	pTemp1 -> pNext = *ppHead2;

	*ppHead2 = NULL;
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

void ConcatList(struct node **ppHead1, struct node **ppHead2)
{
	struct node *pTemp = NULL;
	
	if (NULL == *ppHead2)
		return;

	if(NULL == *ppHead1)
	{
		*ppHead1 = *ppHead2;
		*ppHead2 = NULL;
		return;
	}

	pTemp  = *ppHead1;

	while (pTemp -> pNext != NULL)
		pTemp = pTemp -> pNext;

	pTemp -> pNext = *ppHead2;
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
		*ppHead  = pTemp -> pNext;
		pTemp -> pNext = NULL;
		free(pTemp);
	}

	pTemp = NULL;
}
