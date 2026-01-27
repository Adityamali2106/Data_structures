#include<stdio.h>
#include<malloc.h>

struct node
{
	struct node * pPrev;
	int iData;
	struct node *pNext;
};

void IsertLast(struct node **, int );
void Display(struct node *);
int DeleteFirst(struct node **);

int main(void)
{
	struct node *pFirst = NULL;
	int iDelData;

	IsertLast(&pFirst, 10);
	IsertLast(&pFirst, 20);
	IsertLast(&pFirst, 30);

	Display(pFirst);

	iDelData = DeleteFirst(&pFirst);
	if (iDelData != -1)
		printf("Deleted Node is\t %d \n", iDelData);
	iDelData = DeleteFirst(&pFirst);
	if (iDelData != -1)
		printf("Deleted Node is\t %d \n", iDelData);
	iDelData = DeleteFirst(&pFirst);
	if (iDelData != -1)
		printf("Deleted Node is\t %d \n", iDelData);

	Display(pFirst);

	return 0;
}

void IsertLast(struct node **ppHead, int iNo)
{
	struct node *pNewNode = NULL;
	struct node *pTemp = NULL;

	pNewNode = (struct node *) malloc (sizeof(struct node));

	if (NULL == pNewNode)
	{
		printf("Memory Allocation FAILED\n");
		return;
	}

	pNewNode -> iData = iNo;
	pNewNode -> pNext = NULL;

	if (NULL == *ppHead)
	{
		pNewNode -> pPrev = NULL;

		*ppHead = pNewNode;
		return;
	}

	pTemp = *ppHead;

	while(pTemp -> pNext != NULL)
		pTemp = pTemp -> pNext;

	pTemp -> pNext = pNewNode;
	pNewNode -> pPrev = pTemp;
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
}

int DeleteFirst(struct node **ppHead)
{
	int iDelData;

	if (NULL == *ppHead)
		return -1;

	iDelData = (*ppHead) -> iData;

	if (NULL == (*ppHead)-> pNext )
	{
		free(*ppHead);

		*ppHead = NULL;		
	}
	else
	{
		*ppHead = (*ppHead) -> pNext;

		(*ppHead) -> pPrev -> pNext = NULL;
		free((*ppHead)-> pPrev);

		(*ppHead)-> pPrev = NULL;
	}

	return iDelData;
}
