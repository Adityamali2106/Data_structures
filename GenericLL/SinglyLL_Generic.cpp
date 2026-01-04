#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name : SinglyLLLnode
//  Description    : Represents a node of Singly Linear Linked List
//  Template Type  : T (Generic data type)
//  Members        :
//      data  - Stores value of type T
//      next  - Pointer to next node
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
struct SinglyLLLnode
{
    T data;
    struct SinglyLLLnode<T> *next;
};

////////////////////////////////////////////////////////////////////////////////
//
//  Class Name   : SinglyLLL
//  Description  : Generic (template-based) Singly Linear Linked List.
//                 Supports insertion, deletion, traversal, and counting
//                 operations for any data type.
//  Author       : Aditya Mali
//  Date         : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyLLL
{
    private:
        struct SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
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
//  Constructor Name : SinglyLLL
//  Description      : Initializes linked list with zero nodes.
//  Author           : Aditya Mali
//  Date             : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyLLL<T>::SinglyLLL()
{
    cout<<"Object of SinglyLL get created.\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Displays all elements of the singly linear linked list
//                  from first node to last node.
//  Input         : void
//  Output        : Prints all node data of type T on screen
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::Display()
{
    if(first == NULL)
    {
        return;
    }

    struct SinglyLLLnode<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }
    
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Returns total number of nodes present in the linked list.
//  Input         : void
//  Output        : Integer value representing count of nodes
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Inserts a new node at the beginning of the linked list.
//  Input         : T no → Data to be inserted
//  Output        : Linked list is modified by adding a node at first position
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertFirst(T no)
{
    struct SinglyLLLnode<T> * newn = NULL;

    newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Inserts a new node at the end of the linked list.
//  Input         : T no → Data to be inserted
//  Output        : Linked list is modified by adding a node at last position
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    struct SinglyLLLnode<T> * newn = NULL;
    struct SinglyLLLnode<T> * temp = NULL;

    newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : Inserts a new node at the specified position in the linked list.
//  Input         : T no   → Data to be inserted
//                  int pos → Position at which node is to be inserted
//  Output        : Linked list is modified by inserting node at given position
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertAtPos(T no,int pos)
{
    int iCnt = 0;

    struct SinglyLLLnode<T> * newn = NULL;
    struct SinglyLLLnode<T> * temp = NULL;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new struct SinglyLLLnode<T>;
        newn->data = no;
        newn->next = NULL;

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : Deletes the first node of the linked list.
//  Input         : void
//  Output        : Removes first node and deallocates its memory
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    struct SinglyLLLnode<T> *  temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : Deletes the last node of the linked list.
//  Input         : void
//  Output        : Removes last node and deallocates its memory
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteLast()
{
    struct SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : Deletes a node from the specified position in the linked list.
//  Input         : int pos → Position of node to be deleted
//  Output        : Linked list is modified by removing the node from given position
//  Author        : Aditya Mali
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    int iCnt = 0;

    struct SinglyLLLnode<T> * temp = NULL;
    struct SinglyLLLnode<T> * target = NULL;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : main
//  Description   : Entry point of program to test Singly Linear Linked List
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
int main()
{
    SinglyLLL<int> obj;
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
