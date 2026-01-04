// Doubly Linear Linked List (Using Templates)
// -----------------------------------------------------------------------------
// Description  : Implementation of Doubly Linear Linked List in C++
//                using generic programming (templates).
// Author       : Aditya Mali
// Date         : 04/01/2026
// -----------------------------------------------------------------------------

#include<iostream>
using namespace std;

#pragma pack(1)

////////////////////////////////////////////////////////////////////////
//
// Structure Name : DoublyLLLnode
// Description    : Represents a single node of a Doubly Linear Linked List.
// Template Type  : T (Generic data type)
// Members        :
//      data  - Stores data of generic type
//      next  - Pointer to next node
//      prev  - Pointer to previous node
//
////////////////////////////////////////////////////////////////////////
template <class T>
struct DoublyLLLnode
{
    T data;
    struct DoublyLLLnode<T> *next;
    struct DoublyLLLnode<T> *prev;
};

////////////////////////////////////////////////////////////////////////
//
// Class Name  : DoublyLLL
// Description : Provides functionality to manage Doubly Linear Linked List.
// Features    :
//      - Insertion at first, last, and specific position
//      - Deletion from first, last, and specific position
//      - Display list elements
//      - Count total number of nodes
//
////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyLLL
{
    private:
        struct DoublyLLLnode<T> * first;    // Pointer to first node
        int iCount;                         // Stores number of nodes

    public:
        DoublyLLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

////////////////////////////////////////////////////////////////////////
//
// Constructor Name : DoublyLLL
// Description      : Initializes an empty doubly linked list.
//
////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout<<"Object of DoublyLLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays all elements of the doubly linked list
//                 in forward direction.
// Input         : void
// Output        : Prints node data on console
// Author        : Aditya Mali
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::Display()
{
    struct DoublyLLLnode<T> * temp = first;

    cout<<"\n NULL <=> ";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Returns total number of nodes present in the linked list.
// Input         : void
// Output        : Integer value representing node count
// Author        : Aditya Mali
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Description   : Inserts a new node at the beginning of the linked list.
// Input         : T no → Data to be inserted
// Output        : Linked list is updated
// Author        : Aditya Mali
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    struct DoublyLLLnode<T> * newn = new struct DoublyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts a new node at the end of the linked list.
// Input         : T no → Data to be inserted
// Output        : Linked list is updated
// Author        : Aditya Mali
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    struct DoublyLLLnode<T> * newn = new struct DoublyLLLnode<T>;
    struct DoublyLLLnode<T> * temp = NULL;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Description   : Inserts a node at the specified position.
// Input         : T no  → Data to be inserted
//                 int pos → Position for insertion
// Output        : Linked list is updated
// Author        : Aditya Mali
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertAtPos(T no,int pos)
{
    int iCnt = 0;

    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct DoublyLLLnode<T> * newn = new struct DoublyLLLnode<T>;
        struct DoublyLLLnode<T> * temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Description   : Deletes the first node from the linked list.
// Input         : void
// Output        : Linked list is updated
// Author        : Aditya Mali
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct DoublyLLLnode<T> * temp = first;
        first = first->next;
        first->prev = NULL;
        delete temp;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Description   : Deletes the last node from the linked list.
// Input         : void
// Output        : Linked list is updated
// Author        : Aditya Mali
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct DoublyLLLnode<T> * temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Description   : Deletes a node from the specified position.
// Input         : int pos → Position of node to delete
// Output        : Linked list is updated
// Author        : Aditya Mali
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct DoublyLLLnode<T> * temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        struct DoublyLLLnode<T> * target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////
//
// Entry Point Function : main
// Description          : Demonstrates all operations of
//                        Doubly Linear Linked List.
//
////////////////////////////////////////////////////////////////////////
int main()
{
    DoublyLLL<int> obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.InsertAtPos(105,4);

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    return 0;
}
