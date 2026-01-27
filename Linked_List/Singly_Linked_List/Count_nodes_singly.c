#include <stdio.h>
#include <malloc.h>

struct node
{
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **,int);
int CountNodes(struct node *);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
	struct node *pFirst = NULL;
	int iCount;

	Display(pFirst);
	InsertFirst(&pFirst, 10);
	InsertFirst(&pFirst, 20);
	InsertFirst(&pFirst, 10);
	InsertFirst(&pFirst, 30);
	InsertFirst(&pFirst, 10);
	InsertFirst(&pFirst, 50);
	InsertFirst(&pFirst, 60);

	Display(pFirst);

	iCount = CountNodes(pFirst);

	printf("Total Node Count is: %d \n", iCount);

	DeleteAll(&pFirst);

	Display(pFirst);
	return 0;
}

void InsertFirst(struct node **ppHead,int iNo)
{
	struct node *pNewNode = NULL;

	pNewNode = (struct node *) malloc (sizeof(struct node));
	if (NULL == pNewNode)
	{
		printf("Memory Allocation Failed\n");
		return;
	}

	pNewNode -> iData = iNo;

	if(NULL == *ppHead)
	{
		pNewNode -> pNext = NULL;
	}
	else
	{
		pNewNode -> pNext = *ppHead;
	}

	*ppHead = pNewNode;
}

int CountNodes(struct node *pHead)
{
	int iCount = 0;

	while(pHead != NULL)
	{
		iCount++;
		pHead = pHead -> pNext;
	}

	return iCount;
}

void Display(struct node *pHead)
{
	if (NULL == pHead)
	{
		printf("List Is Empty\n");
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
		free(pTemp);
	}

	pTemp = NULL;
}
