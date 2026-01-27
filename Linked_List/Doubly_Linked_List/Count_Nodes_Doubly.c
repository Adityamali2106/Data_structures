#include <stdio.h>
#include <malloc.h>

struct node
{
	struct node *pPrev;
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **, int);
int CountNodes(struct node *);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
	struct node *pFirst = NULL;
	int iCount = 0;

	InsertFirst(&pFirst, 1);
	Display(pFirst);

	iCount = CountNodes(pFirst);

	printf("Count of Nodes in Linked list is : %d", iCount);

	DeleteAll(&pFirst);
	Display(pFirst);
	
	return 0;
}

void InsertFirst(struct node **ppHead, int iNo)
{
	struct node *pNewNode = NULL;

	pNewNode = (struct node *) malloc (sizeof (struct node));
	if (NULL == pNewNode)
	{
		printf("Memory Allocation Failed\n");
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
		(*ppHead)-> pPrev = pNewNode;
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
		pTemp -> pNext -> pPrev = NULL;
		pTemp -> pNext = NULL;
		free(pTemp);
	}
}
