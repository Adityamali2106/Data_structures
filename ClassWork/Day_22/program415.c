#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;    
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, PPNODE last , int no)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if (*first == NULL && *last == NULL)    // ll is empty
    {
        *first = newn;
        *last = newn;
    }
    else                            // ll contains one or more
    {
        newn -> next = *first;
        (*first) -> prev = newn;
        *first = newn;
    }
    
    (*last) -> next = *first;
    (*first) -> prev = *last;
}

void InsertLast(PPNODE first, PPNODE last , int no)
{
        PNODE newn = NULL;

    newn = (PNODE) malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if (*first == NULL && *last == NULL)    // ll is empty
    {
        *first = newn;
        *last = newn;
    }
    else                            // ll contains one or more
    {

    }
    
    (*last) -> next = *first;
    (*first) -> prev = *last;
}

void DeleteFirst(PPNODE first,PPNODE last)
{}

void Deletelast(PPNODE first,PPNODE last)
{}

void Display(PNODE first,PNODE last)
{
    printf(" <=> ");
    do
    {
        printf("| %d | <=> ",first -> data);
        first = first -> next;
    } while (first != last -> next);
    printf("\n");    
}

int Count(PNODE first,PNODE last)
{
    int iCount = 0;
    do
    {
        iCount++;
        first = first -> next;
    } while (first != last -> next);  

    return iCount;
}

void InsertAtPos(PPNODE first, PPNODE last , int no, int pos)
{}

void DeleteAtPos(PPNODE first,PPNODE last,int pos)
{}

// Segmentation fault due to Display and Count

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;
/*
    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);
*/

    Display(head,tail);
    iRet = Count(head,tail);

    printf("Number of nodes are : %d \n",iRet);

    return 0;
}