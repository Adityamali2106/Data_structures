#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name : SinglyCLLnode
//  Description    : Represents a node of Singly Circular Linked List
//  Template Type  : T (Generic data type)
//  Members        :
//      data  - Stores value of type T
//      next  - Pointer to next node
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

////////////////////////////////////////////////////////////////////////////////
//
//  Class Name   : SinglyCLL
//  Description  : Generic (template-based) Singly Circular Linked List.
//                 The last node points back to the first node.
//                 Supports insertion, deletion, traversal, and counting
//                 operations for any data type.
//  Author       : Aditya Mali
//  Date         : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name : SinglyCLL
//  Description      : Initializes an empty Singly Circular Linked List.
//  Author           : Aditya Mali
//  Date             : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Inserts a new node at the beginning of the circular linked list.
//  Input         : T no → Data to be inserted
//  Output        : Linked list is modified by adding node at first position
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Inserts a new node at the end of the circular linked list.
//  Input         : T no → Data to be inserted
//  Output        : Linked list is modified by adding node at last position
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : Deletes the first node of the circular linked list.
//  Input         : void
//  Output        : Removes first node and deallocates its memory
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : Deletes the last node of the circular linked list.
//  Input         : void
//  Output        : Removes last node and deallocates its memory
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = first;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Displays all elements of the singly circular linked list.
//  Input         : void
//  Output        : Prints all node data of type T on screen
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct SinglyCLLnode<T> * temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    } while(temp != last->next);

    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Returns total number of nodes present in the circular linked list.
//  Input         : void
//  Output        : Integer value representing count of nodes
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : Deletes a node from the specified position in the circular linked list.
//  Input         : int pos → Position of node to be deleted
//  Output        : Linked list is modified by removing the node from given position
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
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
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : Inserts a new node at the specified position in the circular linked list.
//  Input         : T no   → Data to be inserted
//                  int pos → Position at which node is to be inserted
//  Output        : Linked list is modified by inserting node at given position
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * newn = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;
        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : main
//  Description   : Entry point of program to test Singly Circular Linked List
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
int main()
{
    SinglyCLL<int> sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    
    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);
    
    sobj.InsertAtPos(105,5);

    sobj.Display();
    
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteAtPos(5);
    sobj.Display();
    
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteFirst();
    sobj.Display();
    
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteLast();
    sobj.Display();
    
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}
