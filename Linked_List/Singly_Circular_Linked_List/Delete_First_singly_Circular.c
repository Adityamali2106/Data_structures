#include<stdio.h>
#include<malloc.h>

struct node
{
	int iData;
	struct node *pNext;
};

void InsertLast(struct node **,struct node **, int );
void Display(struct node *,struct node *);
int DeleteFirst(struct node **, struct node **);
void DeleteAll(struct node **,struct node **);


int main(void)
{
	struct node *pFirst = NULL;
	struct node *pLast = NULL;
	int iDelData;

	InsertLast(&pFirst,&pLast, 10);
	InsertLast(&pFirst,&pLast, 20);
	InsertLast(&pFirst,&pLast, 30);

	Display(pFirst,pLast);

	iDelData = DeleteFirst(&pFirst,&pLast);
	if (iDelData != -1)
		printf("Deleted Node is\t %d \n", iDelData);
	iDelData = DeleteFirst(&pFirst,&pLast);
	if (iDelData != -1)
		printf("Deleted Node is\t %d \n", iDelData);
	iDelData = DeleteFirst(&pFirst,&pLast);
	if (iDelData != -1)
		printf("Deleted Node is\t %d \n", iDelData);

	Display(pFirst,pLast);

	return 0;
}

void InsertLast(struct node **ppHead, struct node **ppTail, int iNo)
{
	struct node *pNewNode = NULL;

	pNewNode = (struct node *) malloc (sizeof(struct node));

	if (NULL == pNewNode)
	{
		printf("Memory Allocation FAILED\n");
		return;
	}

	pNewNode -> iData = iNo;

	if(NULL == *ppHead)
	{
		*ppHead = pNewNode;
		*ppTail = pNewNode;
		(*ppTail)->pNext = pNewNode;
		return;
	}

	(*ppTail) -> pNext = pNewNode;
	*ppTail = pNewNode;
	(*ppTail)->pNext = *ppHead;
}

int DeleteFirst(struct node **ppHead,struct node **ppTail)
{
	int iDelData;

	if (NULL == *ppHead)
		return -1;
	
	iDelData = (*ppHead) -> iData;

	if(*ppHead == *ppTail)
	{
		(*ppHead) -> pNext = NULL ;
		free(*ppHead);
		*ppHead = *ppTail = NULL;
		return iDelData;
	}

	*ppHead = (*ppHead)-> pNext;
	(*ppTail)->pNext ->pNext = NULL;
	free((*ppTail) -> pNext);

	(*ppTail) -> pNext = *ppHead;
	return iDelData;
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
