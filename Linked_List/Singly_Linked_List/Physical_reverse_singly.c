#include <stdio.h>
#include <malloc.h>

struct node 
{
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **, int);
void PhysicalReverse(struct node **);
void Display(struct node *);
void DeleteAll(struct node **);

int main(int argc, char const *argv[])
{
	struct node *pFirst = NULL;

	InsertFirst(&pFirst,50);
	InsertFirst(&pFirst,40);
	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,10);
	
	Display(pFirst);

	PhysicalReverse(&pFirst);

	Display(pFirst);

	return 0;
}

void PhysicalReverse(struct node **ppHead)
{
	struct node *pNext = NULL;
	struct node *pCurrent = *ppHead;
	struct node *pPrev = NULL;

	while(pCurrent != NULL)
	{
		pNext = pCurrent -> pNext;
		pCurrent -> pNext = pPrev;
		pPrev = pCurrent;
		pCurrent = pNext;
	}

	*ppHead = pPrev;
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
