#include<stdio.h>
#include <malloc.h>

struct node
{
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
	struct node *pSecond = NULL;
	struct node *pLast2 = NULL;


   	InsertLast(&pFirst,&pLast, 10);
	InsertLast(&pFirst,&pLast, 20);
	InsertLast(&pFirst,&pLast, 50);
	InsertLast(&pFirst,&pLast, 60);

	InsertLast(&pSecond,&pLast2, 100);
	InsertLast(&pSecond,&pLast2, 200);
	InsertLast(&pSecond,&pLast2, 300);

	Display(pFirst,pLast);
	Display(pSecond,pLast2);
	ConcatList(&pFirst,&pLast,&pSecond,&pLast2);
	Display(pFirst,pLast);
	Display(pSecond,pLast2);

	return 0;
}

void ConcatList(struct node **ppHead1,struct node **ppTail1,struct node **ppHead2,struct node **ppTail2)
{
	if(NULL == *ppHead2)
		return;

	if(NULL == *ppHead1)
	{
		*ppHead1 = *ppHead2;
		*ppTail1 = *ppTail2;
	}
	else
	{		
		(*ppTail1) -> pNext = *ppHead2;
		*ppTail1 = *ppTail2;
		(*ppTail2) -> pNext = *ppHead1;
	}

	*ppHead2 = *ppTail2 = NULL;
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

