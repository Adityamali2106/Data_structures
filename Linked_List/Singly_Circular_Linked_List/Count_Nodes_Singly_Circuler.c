#include<stdio.h>
#include <malloc.h>

struct node
{
	struct node *pPrev;
	int iData;
	struct node *pNext;
};


void InsertLast(struct node **,struct node **, int);
int DeleteFirst(struct node **,struct node **);
int CountNodes(struct node *,struct node *);
void Display(struct node *,struct node *);
void DeleteAll(struct node **,struct node **);

int main(void)
{
	int iData;
	struct node *pFirst = NULL;
	struct node *pLast = NULL;

   	InsertLast(&pFirst,&pLast, 10);
	InsertLast(&pFirst,&pLast, 20);
	InsertLast(&pFirst,&pLast, 10);
	InsertLast(&pFirst,&pLast, 30);
	InsertLast(&pFirst,&pLast, 10);

    iData = CountNodes(pFirst,pLast);

    printf("\nTotal Number of nodes present in linked list are : %d\n",iData);

    printf("\nLinked list is : \n");

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
