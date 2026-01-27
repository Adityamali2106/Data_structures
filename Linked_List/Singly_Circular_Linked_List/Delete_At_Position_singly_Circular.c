#include<stdio.h>
#include <malloc.h>

struct node
{
	int iData;
	struct node *pNext;
};


void InsertLast(struct node **,struct node **, int);
int DeleteFirst(struct node **,struct node **);
int DeleteLast(struct node **,struct node **);
int DeleteAtPosition(struct node **,struct node **, int);
int CountNodes(struct node *,struct node *);
void Display(struct node *,struct node *);
void DeleteAll(struct node **,struct node **);

int main(void)
{
	int iDelData;
	struct node *pFirst = NULL;
	struct node *pLast = NULL;

   	InsertLast(&pFirst,&pLast, 10);
	InsertLast(&pFirst,&pLast, 20);
	InsertLast(&pFirst,&pLast, 50);
	InsertLast(&pFirst,&pLast, 60);
	InsertLast(&pFirst,&pLast, 90);
	InsertLast(&pFirst,&pLast, 36);

    printf("Before calling DeleteAtPosition linked list is : \n");
    Display(pFirst,pLast);

    iDelData = DeleteAtPosition(&pFirst,&pLast,4);
	if (iDelData != -1)
		printf("Deleted Node is\t %d \n", iDelData);

    printf("Before calling DeleteAtPosition linked list is : \n");
    Display(pFirst,pLast);

    DeleteAll(&pFirst,&pLast);

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

int DeleteLast(struct node **ppHead,struct node **ppTail)
{
	int iDelData;
	struct node *pTemp = NULL;

	if(NULL == *ppHead)
		return -1;

	if(*ppHead  == *ppTail)
	{
		iDelData = (*ppHead) -> iData;
		(*ppHead)->pNext = NULL;
		free(*ppHead);
		*ppHead = *ppTail = NULL;
		return iDelData;
	}	

	pTemp = *ppHead;

	while(pTemp ->pNext != *ppTail)
		pTemp= pTemp -> pNext;

	iDelData = (*ppTail) -> iData;
	pTemp -> pNext = (*ppTail)->pNext;
	free(*ppTail);
	*ppTail = pTemp;

	return iDelData;
}

int DeleteAtPosition(struct node **ppHead,struct node **ppTail, int iPos)
{
	struct node *pTemp1 = NULL;
	struct node *pTemp2 = NULL;
	int iCount = CountNodes(*ppHead,*ppTail);

	if (iPos <=  0 || iPos > iCount)
	{
		printf("Position Is Invalid \n");
		return -1;
	}

	if (1 == iPos)
		return DeleteFirst(ppHead,ppTail);
	
	pTemp1 = *ppHead;
	iCount = 1;

	while(iCount < iPos -1)
	{
		iCount ++;
		pTemp1 = pTemp1-> pNext;
	}

	pTemp2 = pTemp1 -> pNext;
	pTemp1 -> pNext = pTemp2 -> pNext;

	iCount  = pTemp2 -> iData;

	pTemp2 -> pNext = NULL;
	free(pTemp2);

	pTemp1 = pTemp2 = NULL;

	return iCount;
}

void Display(struct node *pHead,struct node *pTail)
{
	if (NULL == pHead)
	{
		printf("List is Empty\n");
		return;
	}

	do
	{
		printf("|%d|->", pHead -> iData);
		pHead = pHead-> pNext;
	}while(pHead != pTail -> pNext);
	printf("\n");
}

int CountNodes(struct node *pHead,struct node *pTail)
{
	int iCount = 0;

	if(NULL == pHead)
		return 0;

	do
	{
		iCount++;
		pHead = pHead -> pNext;
	}while(pHead != pTail -> pNext);

	return iCount;
}

void DeleteAll(struct node **ppHead, struct node **ppTail)
{
	struct node *pTemp = NULL;
	(*ppTail) ->pNext = NULL;

	while(*ppHead != NULL)
	{
		pTemp = *ppHead;
		*ppHead = pTemp -> pNext;
		pTemp -> pNext = NULL;
		free(pTemp);
	}

	pTemp = NULL;
}
