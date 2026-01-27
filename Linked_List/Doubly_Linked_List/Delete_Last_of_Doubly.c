#include <stdio.h>
#include <malloc.h>

struct node
{
	struct node *pPrev;
	int iData;
	struct node *pNext;
};

void IsertLast(struct node **, int );
void Display(struct node *);
int DeleteLast(struct node **);

int main(void)
{
	struct node *pFirst = NULL;
	int iDelData;

	IsertLast(&pFirst, 10);
	IsertLast(&pFirst, 20);
	IsertLast(&pFirst, 30);

	Display(pFirst);

	iDelData = DeleteLast(&pFirst);
	if (iDelData != -1)
		printf("Deleted Node is\t %d \n", iDelData);
	iDelData = DeleteLast(&pFirst);
	if (iDelData != -1)
		printf("Deleted Node is\t %d \n", iDelData);
	iDelData = DeleteLast(&pFirst);
	if (iDelData != -1)
		printf("Deleted Node is\t %d \n", iDelData);

	Display(pFirst);

	return 0;
}


void IsertLast(struct node **ppHead , int iNo)
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
	}
	else
	{
		pTemp = *ppHead;

		while(pTemp -> pNext != NULL)
			pTemp = pTemp -> pNext;

		pTemp -> pNext = pNewNode;
		pNewNode -> pPrev = pTemp;
	}
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

int DeleteLast(struct node ** ppHead)
{
	int iDelData;
	struct node *pTemp = NULL;

	if (NULL == *ppHead)
		return -1;


	if ((*ppHead) -> pNext == NULL)
	{
		iDelData = (*ppHead) -> iData;

		free(*ppHead);
		*ppHead = NULL;
	}
	else
	{
		pTemp = *ppHead;
		while(pTemp-> pNext -> pNext != NULL)
			pTemp = pTemp -> pNext;

		iDelData = pTemp-> pNext -> iData;

		pTemp -> pNext -> pPrev = NULL;
		free(pTemp -> pNext);

		pTemp -> pNext = NULL;
	}

	return iDelData;
}

