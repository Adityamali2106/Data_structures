#include <stdio.h>
#include <malloc.h>

struct node
{
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **,int);
void Display(struct node *);
void DeleteAll(struct node **);

int main(void)
{
	struct node *pFirst = NULL;

	Display(pFirst);
	InsertFirst(&pFirst, 10);
	InsertFirst(&pFirst, 20);
	InsertFirst(&pFirst, 30);

	Display(pFirst);

	if (pFirst != NULL)
	{
		DeleteAll(&pFirst);
		pFirst = NULL;
	}
	Display(pFirst);
	return 0;
}

void InsertFirst(struct node **ppHead ,int iNo)
{
	struct node *pNewNode = NULL;

	pNewNode = (struct node *) malloc (sizeof(struct node));
	if (NULL == pNewNode)
	{
		printf("MEmpry Allocation FAILED\n");
		return;
	}

	pNewNode -> iData = iNo;

	if (NULL == *ppHead)
	 	pNewNode -> pNext = NULL;
	else
		pNewNode -> pNext = *ppHead;

	*ppHead = pNewNode;
}

void Display(struct node *pHead)
{
	if (pHead == NULL)
	{
		printf("List is Empty\n");
		return;
	}

	while(pHead != NULL)
	{
		printf("|%d|-> ", pHead -> iData);
		pHead = pHead -> pNext;
	}
}

void DeleteAll(struct node **ppHead)
{
	struct node *pTemp = NULL;

	if (NULL == *ppHead)
		return;

	while(*ppHead != NULL)
	{
		pTemp = *ppHead;
		*ppHead  = pTemp -> pNext;

		pTemp -> pNext = NULL;
		free(pTemp);
	}

	pTemp  = NULL;
}
