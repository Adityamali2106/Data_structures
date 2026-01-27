#include<stdio.h>
#include<malloc.h>

struct node
{
	struct node * pPrev;
	int iData;
	struct node *pNext;
};

void InsertLast(struct node **, int );
void Display(struct node *);
int SearchFirstOccurrence(struct node *, int);
int DeleteAll(struct node **);


int main(void)
{
	struct node *pFirst = NULL;
	int iPos;

	Display(pFirst);
	InsertLast(&pFirst, 10);
	InsertLast(&pFirst, 20);
	InsertLast(&pFirst, 10);
	InsertLast(&pFirst, 30);
	InsertLast(&pFirst, 10);
	InsertLast(&pFirst, 50);
	InsertLast(&pFirst, 60);

	Display(pFirst);

	iPos = SearchFirstOccurrence(pFirst, 10);

	if(iPos != 0)
		printf("10 Found at %d Position \n", iPos);

	DeleteAll(&pFirst);

	Display(pFirst);
	return 0;
}

void InsertLast(struct node **ppHead, int iNo)
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

int SearchFirstOccurrence(struct node *pHead, int iKey)
{
	int iCnt = 0;
    int iPos = 0;

	while(pHead != NULL)
	{
		iCnt++;
		if(pHead -> iData == iKey)
		    iPos = iCnt;
		pHead = pHead -> pNext;
	}

	return iPos;
}

int DeleteAll(struct node **ppHead)
{
	struct node *pTemp = NULL;
	
	while(*ppHead != NULL)
	{
		pTemp = *ppHead;
		*ppHead = pTemp -> pNext;
		pTemp -> pNext = NULL;
		pTemp -> pPrev = NULL;
		free(pTemp);
	}

	pTemp = NULL;
}
