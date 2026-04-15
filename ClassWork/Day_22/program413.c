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
{}

void InsertLast(PPNODE first, PPNODE last , int no)
{}

void DeleteFirst(PPNODE first,PPNODE last)
{}

void Deletelast(PPNODE first,PPNODE last)
{}

void Display(PNODE first,PNODE last)
{}

int Count(PNODE first,PNODE last)
{
    return 0;
}

void InsertAtPos(PPNODE first, PPNODE last , int no, int pos)
{}

void DeleteAtPos(PPNODE first,PPNODE last,int pos)
{}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    return 0;
}