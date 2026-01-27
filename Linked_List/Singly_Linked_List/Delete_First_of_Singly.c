#include<stdio.h>
#include<malloc.h>

struct node
{
	int iData;
	struct node *pNext;
};

void IsertLast(struct node **, int );
void Display(struct node *);
int DeleteFirst(struct node **);
void DeleteAll(struct node **);


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

	DeleteAll(&pFirst);
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
		*ppHead = pNewNode;
	}
	else
	{
		pTemp = *ppHead;

		while(pTemp -> pNext != NULL)
			pTemp = pTemp -> pNext;

		pTemp-> pNext = pNewNode;
	}
}

void Display(struct node *pHead)
{
	if (NULL == pHead)
	{
		printf("List is Empty\n");
		return;
	}

	while (pHead != NULL)
	{
		printf("|%d|-> \t", pHead -> iData);
		pHead = pHead -> pNext;
	}
	printf("\n");
}

int DeleteFirst(struct node **ppHead)
{
	int iDelData;
	struct node *pTemp = NULL;

	if (NULL == *ppHead)
		return -1;
	
	iDelData = (*ppHead) -> iData;

	if(NULL == (*ppHead)->pNext)
	{
		free(*ppHead);
		*ppHead = NULL;
		return iDelData;
	}

	pTemp = *ppHead;
	*ppHead = pTemp -> pNext;
	pTemp-> pNext = NULL;
	free(pTemp);

	return iDelData;
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


