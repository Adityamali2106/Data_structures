#include <stdio.h>
#include <malloc.h>

struct node 
{
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

	ConcatList(&pFirst, &pSecound);

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
