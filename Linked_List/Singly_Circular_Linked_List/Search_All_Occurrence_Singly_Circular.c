#include<stdio.h>
#include <malloc.h>

struct node
{
	int iData;
	struct node *pNext;
};


void InsertLast(struct node **,struct node **, int);
int SearchAllOccurrences(struct node *,struct node *, int);
void Display(struct node *,struct node *);
void DeleteAll(struct node **,struct node **);

int main(void)
{
	struct node *pFirst = NULL;
	struct node *pLast = NULL;
    int iPos;

	Display(pFirst,pLast);
	InsertLast(&pFirst,&pLast, 10);
	InsertLast(&pFirst,&pLast, 20);
	InsertLast(&pFirst,&pLast, 10);
	InsertLast(&pFirst,&pLast, 30);
	InsertLast(&pFirst,&pLast, 10);
	InsertLast(&pFirst,&pLast, 50);
	InsertLast(&pFirst,&pLast, 60);

	Display(pFirst,pLast);

	iPos = SearchAllOccurrences(pFirst,pLast, 10);

	if(iPos != 0)
    {
		printf("10 Found %d Times \n", iPos);
    }

	DeleteAll(&pFirst,&pLast);

	Display(pFirst,pLast);

    return 0;
}

int SearchAllOccurrences(struct node *pHead ,struct node *pTail , int iKey)
{
	int iCount = 0;
	int iPos = 0;
	if(NULL == pHead)
		return 0;

	do 
	{
		iPos++;
		if(iKey == pHead -> iData)
			iCount ++;
		pHead = pHead -> pNext;
	}while(pHead != pTail -> pNext);

	return iCount;
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
