#include<stdio.h>
#include <malloc.h>

struct node
{
	struct node *pPrev;
	int iData;
	struct node *pNext;
};


void InsertFirst(struct node **,struct node **, int);
void InsertLast(struct node **,struct node **, int);
void InsertAtPosition(struct node **,struct node **, int, int);
int DeleteFirst(struct node **,struct node **);
int DeleteLast(struct node **,struct node **);
int DeleteAtPosition(struct node **,struct node **, int);
int SearchFirstOccurrence(struct node *,struct node *, int);
int SearchLastOccurrence(struct node *,struct node *, int);
int SearchAllOccurrences(struct node *,struct node *, int);
int CountNodes(struct node *,struct node *);
void Display(struct node *,struct node *);
void PhysicalReverse(struct node **,struct node **);
void ReverseDisplay(struct node *,struct node *);
void ConcatList(struct node **,struct node **,struct node **,struct node **);
void ConcatAtPosition(struct node **, struct node **,struct node **,struct node **, int);
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
    
    return 0;
}
void InsertLast(struct node **ppHead ,struct node **ppTail, int iNo)
{
	struct node *pNewNode = NULL;

	pNewNode = (struct node *) malloc (sizeof(struct node));

	if (NULL == pNewNode)
	{
		printf("Memory Allocation FAILED\n");
		return;
	}

	pNewNode -> iData = iNo;

	if (NULL == *ppHead)
	{
		*ppHead = pNewNode;
		*ppTail = pNewNode;
		(*ppTail) -> pNext = *ppHead;
		(*ppHead) -> pPrev = *ppTail;
		return;
	}

	(*ppTail) -> pNext = pNewNode;
	pNewNode -> pPrev = *ppTail;
	*ppTail = pNewNode;
	(*ppTail) -> pNext = *ppHead;
	(*ppHead) -> pPrev = *ppTail;
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
