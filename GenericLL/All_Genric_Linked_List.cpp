//////////////////////////////////////////////////////////////////
//  Generalised Data Structure Library
//////////////////////////////////////////////////////////////////

/*
--------------------------------------------------------------------------------------------------
Type                    Name of class ofr node                  Name of class for Functionality
--------------------------------------------------------------------------------------------------
Singly Linear           SinglyLLLnode                           SinglyLLL           Done
Singly Cirular          SinglyCLLnode                           SinglyCLL           Done
Doubly Linear           DoublyLLLnode                           DoublyLLL           Done
Doubly cirular          DoublyCLLnode                           DoublyCLL           Done
--------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
//      Singly Linear linked List using Genric Approch
///////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> * next;

        SinglyLLLnode(T no)
        {
            this -> data = no;
            this -> next = NULL;
        }
};  // End of Class SinglyLLLnode

template <class T>
class SinglyLLL
{
    private:
        SinglyLLLnode<T> * first;
        int iCount;

    public: 
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast(); 
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
        void DeleteAll();
};  // End of Class Diclaration

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SinglyLLL
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Construct the class SinglyLLL
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of Singlyll gets created. \n";
    this -> first = NULL;
    this -> iCount = 0;
}   // end of SinglyLLL

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertFirst
//  Input           : Data of Node
//  Output          : Nothing
//  Description     : Used to insert node at first position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn -> next = this -> first;
    this -> first = newn;

    this -> iCount++;
}   // End of InsertFirst

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertLast
//  Input           : Data of Node
//  Output          : Nothing
//  Description     : Used to insert node at last position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);
    
    if (this -> iCount == 0)            // Updated
    {
        this -> first = newn;
    }
    else
    {
        temp = this -> first;

        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    this -> iCount++;
}   //End of InsertLast

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteFirst
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Delete node at first position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;
    if (this -> first == NULL)
    {
        return;
    }
    else if(this -> first -> next == NULL)      // else if(this -> iCount == 1)
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;
        this -> first = this -> first -> next;
        delete temp;
    }

    this -> iCount--;
}   // End of DeleteFirst

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteLast
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Delete node at last position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if (this -> first == NULL)
    {
        return;
    }
    else if(this -> first -> next == NULL)      // else if(this -> iCount == 1)
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;

        while (temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;                
    }

    this -> iCount--;
}   // End of DeleteLast

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertAtPos
//  Input           : Data of Node
//  Output          : Nothing
//  Description     : Used to insert node at Given position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no,int pos)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    int iCnt = 0;

    if (pos < 1 || pos > this -> iCount + 1)
    {
        cout<<"Invalid position \n";
        return;
    }

    if (pos == 1)
    {
        this -> InsertFirst(no);
    }
    else if(pos == this -> iCount +1)
    {
        this -> InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this -> first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn-> next = temp -> next;
        temp -> next = newn;

        this -> iCount++;
    }            
}   // End of InsertAtPos

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteAtPos
//  Input           : Position
//  Output          : Nothing
//  Description     : Used to Delete node of given position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;
    int iCnt = 0;

    if (pos < 1 || pos > this -> iCount + 1)
    {
        cout<<"Invalid position \n";
        return;
    }

    if (pos == 1)
    {
        this -> DeleteFirst();
    }
    else if(pos == this -> iCount)
    {
        this -> DeleteLast();
    }
    else
    {
        temp = this -> first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        
        target = temp -> next;
        temp -> next = target -> next;
        delete target;

        this -> iCount--;
    }
}   // End of DeleteAtPos

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Display linked list
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> * temp = NULL;
    if (this -> first == NULL)
    {
        cout<<"\nLinked List is Empty\n";
    }
    else
    {
        temp = this -> first;

        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" | -> ";
            temp = temp -> next;
        }

        cout <<"NULL \n";
    }
}   // End of Display

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Count
//  Input           : Nothing
//  Output          : Integer
//  Description     : Used to Count the nodes of the linked list and return it to caller
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T> :: Count()
{
    return this -> iCount;
}   // End of Count

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteAll
//  Input           : Position
//  Output          : Nothing
//  Description     : Used to Delete All nodes of linked list 
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteAll()
{
    SinglyLLLnode<T> *temp =NULL;

    while(this -> first != NULL)
    {
        temp = this -> first;
        first = temp -> next;
        delete temp;
        this -> iCount--;
    }
    this -> Display();
}

///////////////////////////////////////////////////////////////////////////////////
//      Doubly Linear linked List using Genric Approch
///////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)
template <class  T>
class DoublyLLLnode
{
    public :
        T data;
        DoublyLLLnode * next;
        DoublyLLLnode * prev;

        DoublyLLLnode(T no)
        {
            this -> data = no;
            this -> next = NULL;
            this -> prev = NULL;
        }
};  // End of Class DoublyLLLnode

template <class  T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;
        
    public :
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void DeleteAll();

        void Display();
        int Count();
};  // End of Class DoublyLLL Diclaration

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DoublyLLL
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Construct the object
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class  T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List gets created \n";
    this -> first = NULL;
    this -> iCount = 0;
}      // End of DoublyLLL

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertFirst
//  Input           : Data of Node
//  Output          : Nothing
//  Description     : Used to insert node at first position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class  T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if (this-> first == NULL)
    {
        this ->first = newn;
    }
    else
    {
        newn -> next = this -> first;
        this -> first -> prev = newn;
        this -> first = newn; 
    }

    this -> iCount++;
}   // End of InsertFirst

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertLast
//  Input           : Data of Node
//  Output          : Nothing
//  Description     : Used to insert node at last position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class  T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if (first == NULL)
    {
        this -> first = newn;
    }
    else
    {
        temp = this -> first;

        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        newn -> prev = temp;
    }

    this -> iCount++;
}   // End of InsertLast

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertAtPos
//  Input           : Data of Node
//  Output          : Nothing
//  Description     : Used to insert node at Given position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class  T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if (pos < 1 || pos > iCount +1 )
    {
        cout<< "Invalid Position\n";
        return;
    }
    
    if (pos == 1)
    {
        this -> InsertFirst(no);
    }
    else if (pos == iCount + 1)
    {
        this -> InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);
        temp = this -> first;

        for (iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;

        this -> iCount++;
    }
}   // End of InsertAtPos

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteFirst
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Delete node at first position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class  T>
void DoublyLLL<T> :: DeleteFirst()
{
    if (this -> first == NULL)
    {
        return;
    }
    else if (this -> first -> next == NULL)
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        this -> first = this -> first -> next;
        delete first -> prev;
        this -> first -> prev = NULL;
    }
    
    this -> iCount--;
}   // End of DeleteFirst

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteLast
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Delete node at last position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class  T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> * temp = NULL;
    if (this -> first == NULL)
    {
        return;
    }
    else if (this -> first -> next == NULL)
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;

        while (temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        
        delete temp -> next;
        temp -> next = NULL;
    }
    this -> iCount--;
}   // End of Delete Last

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteAtPos
//  Input           : Position
//  Output          : Nothing
//  Description     : Used to Delete the node of Given position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class  T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if (pos < 1 || pos > this ->iCount)
    {
        cout<< "Invalid Position\n";
        return;
    }
    
    if (pos == 1)
    {
        this -> DeleteFirst();
    }
    else if (pos == iCount)
    {
        this -> DeleteLast();
    }
    else
    {
        temp = this -> first;

        for (iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        this -> iCount--;        
    }
}   // End of DeleteAtPos

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Display All nodes present in linked list
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class  T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> * temp = NULL;

    if (this -> first == NULL)
    {
        cout <<"Linked list is Empty";
        return;
    }

    cout<<"\nNULL <=> ";
    temp = this -> first;

    while (temp != NULL)
    {
        cout<<"| "<<temp -> data<<" | <=>";
        temp = temp -> next;
    }
    cout<<"NULL \n";  
}   // End of Display

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Count
//  Input           : Nothing
//  Output          : Integer
//  Description     : Used to Count the nodes of the linked list and return it to caller
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class  T>
int DoublyLLL<T> :: Count()
{
    return this -> iCount;
}   // End of Count

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteAll
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Delete All nodes of linked list 
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteAll()
{
    DoublyLLLnode<T> *temp =NULL;

    while(this -> first != NULL)
    {
        temp = this -> first;
        first = temp -> next;
        delete temp;
        this -> iCount--;
    }
    this -> Display();
}   // End of DeleteAll

///////////////////////////////////////////////////////////////////////////////////
//      Singly Circular linked List using Genric Approch
///////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this -> data = no;
            this -> next = NULL;
        }
};  // End of Class SinglyCLLnode

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;
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
        void DeleteAll();
};  // End of Class Diclaration SinglyCLL

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : SinglyCLL
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Construct the object
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}   // End of SinglyCLL

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertFirst
//  Input           : Data of Node
//  Output          : Nothing
//  Description     : Used to insert node at first position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if((this -> first == NULL) && (this -> last == NULL))   // if(iCount == 0)
    {
        this -> first = newn;
        this -> last = newn;

        this -> last -> next = this -> first;
    }
    else
    {
        newn -> next = this -> first;
        this -> first = newn;

        this -> last -> next = this -> first;
    }

    this -> iCount++;
}   // End of InsertFirst

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertLast
//  Input           : Data of Node
//  Output          : Nothing
//  Description     : Used to insert node at last position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if((this -> first == NULL) && (this -> last == NULL))
    {
        this -> first = newn;
        this -> last = newn;

        this -> last -> next = this -> first;
    }
    else
    {
        this -> last -> next = newn;
        this -> last = newn;

        this -> last -> next = this -> first;
    }

    this -> iCount++;
}   // End of InsertLast

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteFirst
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Delete node at first position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if((this -> first == NULL) && (this -> last == NULL))
    {
        return;
    }
    else if((this -> first) == (this -> last))
    {
        delete this -> first;

        this -> first = NULL;
        this -> last = NULL;
    }
    else
    {
        this -> first = this -> first -> next;
        delete this -> last->next;

        this -> last->next = first;
    }
    this -> iCount--;
}   // End Of DeleteFirst

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteLast
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Delete node at last position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if(this -> first == NULL && this -> last == NULL)
    {
        return;
    }
    else if(this -> first == this -> last)
    {
        delete this -> first;

        this -> first = NULL;
        this -> last = NULL;
    }
    else
    {
        temp = this -> first;

        while(temp -> next != this -> last)
        {
            temp = temp -> next;
        }

        delete this ->last;
        this -> last = temp;

        this -> last->next = first;
    }
    this -> iCount--;
}   // End of DeleteLast

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteAtPos
//  Input           : Position
//  Output          : Nothing
//  Description     : Used to Delete the node of Given position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;
    
    int iCnt = 0;
    
    if(pos < 1 || pos > this -> iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this -> DeleteFirst();
    }
    else if(pos == this -> iCount)
    {
        this -> DeleteLast();
    }
    else
    {
        temp = this -> first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        this -> iCount--;
    }
}   // End of DeleteAtPos

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertAtPos
//  Input           : Data of Node
//  Output          : Nothing
//  Description     : Used to insert node at Given position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this -> iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this -> InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        this -> InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = this -> first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        this -> iCount++;
    }
}   // End of InsertAtPos

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Display All nodes present in linked list
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::Display()
{
    SinglyCLLnode<T> * temp = NULL;
    if((this -> first == NULL) && (this -> last == NULL))
    {
        cout<<"Linked List is Empty\n";
        return;
    }

    temp = this -> first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != this -> last ->next);
    
    cout<<"\n";
}   // End of Display

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Count
//  Input           : Nothing
//  Output          : Integer
//  Description     : Used to Count the nodes of the linked list and return it to caller
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T>::Count()
{
    return this -> iCount;
}   // End of Count 

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteAll
//  Input           : Position
//  Output          : Nothing
//  Description     : Used to Delete All nodes of linked list 
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteAll()
{
    SinglyCLLnode<T> *temp = NULL;

    if (this -> iCount == 0) 
    {
        return;
    }

    temp = this -> first;
    this -> last -> next = NULL;

    while(this -> first != NULL)
    {
        temp = this -> first;
        this -> first = this -> first -> next;
        delete temp;
        this -> iCount--;
    }
    this -> Display();
}

///////////////////////////////////////////////////////////////////////////////////
//  Doubly Circular linked List using Genric Approch
///////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T no)
        {
            this -> data = no;
            this -> next = NULL;
            this -> prev = NULL;
        }
};  // End of Class DoublyCLLnode

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLnode <T> * first;
        DoublyCLLnode <T> * last;
        int iCount;

    public:
        DoublyCLL()
        {
            cout<<"object of DoublyCLL gets created.\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int pos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
        void DeleteAll();
        void Display();
        int Count();
};  // End of Class Diclatration DoublyCLL

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertFirst
//  Input           : Data of Node
//  Output          : Nothing
//  Description     : Used to insert node at first position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode <T> * newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if ((this -> first == NULL) && (this -> last == NULL))
    {
        this -> first = newn;
        this -> last = newn;
    }
    else 
    {
        newn -> next = this -> first;
        this -> first -> prev = newn;
        this -> first = newn;
    }

    this -> first -> prev = this -> last;
    this -> last -> next = this -> first;

    this -> iCount++;
}   // End of InsertFirst

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertLast
//  Input           : Data of Node
//  Output          : Nothing
//  Description     : Used to insert node at last position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode <T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if ((this -> first == NULL) && (this -> last == NULL))
    {
        this -> first = newn;
        this -> last = newn;
    }
    else 
    {
        newn -> prev = this -> last;
        this -> last -> next = newn;
        this -> last = newn;
    }

    this -> last -> next = this -> first;
    this -> first -> prev = this -> last;
    this -> iCount++;
}   // End of InsertLast

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : InsertAtPos
//  Input           : Data of Node
//  Output          : Nothing
//  Description     : Used to insert node at Given position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyCLLnode <T> * newn = NULL;
    DoublyCLLnode <T> * temp = NULL;
    int iCnt = 0;

    if (pos < 1 || pos > this -> iCount + 1)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if (pos == 1)
    {
        this -> InsertFirst(no);
    }
    else if (pos == iCount + 1)
    {
        this -> InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);

        temp = this -> first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;

        this -> iCount++;
    }
}   // End Of InsertAtPos

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteFirst
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Delete node at first position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if ((this -> first == NULL) && (this -> last == NULL))
    {
        return;
    }
    else if ((this -> first) == (this -> last))
    {
        delete this -> first;
        this -> first = NULL;
        this -> last = NULL;
    }
    else
    {
        this -> first = this -> first -> next;
        delete this -> first -> prev;

        this -> last -> next = this -> first;
        this -> first -> prev = this -> last;
    }
    this -> iCount--;
}   // End of DeleteFirst

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteLast
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Delete node at last position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    if ((this -> first == NULL) && (this -> last == NULL))
    {
        return;
    }
    else if ((this -> first) == (this -> last))
    {
        delete this -> first;
        this -> first = NULL;
        this -> last = NULL;
    }
    else
    {
        this -> last = this -> last -> prev;
        delete this -> last -> next;

        this -> first -> prev = this -> last;
        this -> last -> next = this -> first;
    }
    this -> iCount--;
}   // End of DeleteLast

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteAtPos
//  Input           : Position
//  Output          : Nothing
//  Description     : Used to Delete the node of Given position
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    DoublyCLLnode <T> * temp = NULL;
    int iCnt = 0;

    if (pos < 1 || pos > this -> iCount)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if (pos == 1)
    {
        this -> DeleteFirst();
    }
    else if (pos == iCount)
    {
        this -> DeleteLast();
    }
    else
    {
        temp = this -> first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        this -> iCount--;
    }
}   // End of DeleteAtPos

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Display
//  Input           : Nothing
//  Output          : Nothing
//  Description     : Used to Display All nodes present in linked list
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLnode <T> *temp = NULL;
    if ((this -> first == NULL) && (this -> last == NULL))
    {
        cout<<"List is Empty";
        return;
    }

    temp = this -> first;

    do
    {
        cout<<"| "<<temp-> data<<" | <=>";
        temp = temp -> next;
    }while(temp  != this -> last -> next);

    cout<<endl;
}   //End of Display

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : Count
//  Input           : Nothing
//  Output          : Integer
//  Description     : Used to Count the nodes of the linked list and return it to caller
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T> :: Count()
{
    return this -> iCount;
}   //End of Count

///////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : DeleteAll
//  Input           : Position
//  Output          : Nothing
//  Description     : Used to Delete All nodes of linked list 
//  Author          : Aditya Vijay Mali
//  Date            : 06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteAll()
{
    DoublyCLLnode <T> *temp =NULL;

    if ((this -> first == NULL) && (this -> last == NULL))
    {
        return;
    }

    temp = this -> first;
    this -> last -> next = NULL;

    while(this -> first != NULL)
    {
        temp = this -> first;
        this -> first = this -> first -> next;
        delete temp;
        this -> iCount--;
    }
    this -> Display();
}


//////////////////////////////////////// End of Library ///////////////////////////////////////////

int main()
{
    cout<<"\nSingly Linear Linked list\n";
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;

    obj -> InsertFirst(51);
    obj -> InsertFirst(21);
    obj -> InsertFirst(11);

    obj -> Display();

    iRet = obj -> Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj -> InsertLast(101);
    obj -> InsertLast(111);
    obj -> InsertLast(121);

    obj -> Display();

    iRet = obj -> Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj -> DeleteFirst();
    
    obj -> Display();
    iRet = obj -> Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj -> DeleteLast();

    obj -> Display();
    iRet = obj -> Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj -> InsertAtPos(105,4);

    obj -> Display();
    iRet = obj -> Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj -> DeleteAtPos(4);

    obj -> Display();
    iRet = obj -> Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj -> DeleteAll();

    delete obj;
///////////////////////////////////////////////////////////////////////////////////////
    
    cout<<"\nDoubly Linear Linked list\n\n";
    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj -> Display();
    cout<<"Number of elements Are : "<<dobj -> Count()<<"\n";

    dobj -> InsertLast('X');
    dobj -> InsertLast('Y');
    dobj -> InsertLast('Z');

    dobj -> Display();
    cout<<"Number of elements Are : "<<dobj -> Count()<<"\n";

    dobj -> DeleteFirst();

    dobj -> Display();
    cout<<"Number of elements Are : "<<dobj -> Count()<<"\n";

    dobj -> DeleteLast();

    dobj -> Display();
    cout<<"Number of elements Are : "<<dobj -> Count()<<"\n";

    dobj -> InsertAtPos('$',4);

    dobj -> Display();
    cout<<"Number of elements Are : "<<dobj -> Count()<<"\n";

    dobj -> DeleteAtPos(4);

    dobj -> Display();
    cout<<"Number of elements Are : "<<dobj -> Count()<<"\n";

    dobj -> DeleteAll();

    delete dobj;

///////////////////////////////////////////////////////////////////////////////////////
    
    cout<<"\nSingly Circular Linked list\n\n";
    SinglyCLL<int> *sobj = new SinglyCLL<int>();

    sobj -> InsertFirst(51);
    sobj -> InsertFirst(21);
    sobj -> InsertFirst(11);

    sobj -> Display();
    cout<<"Number of elements are : "<<sobj -> Count()<<"\n";

    sobj -> InsertLast(101);
    sobj -> InsertLast(111);
    sobj -> InsertLast(121);
    
    sobj -> Display();
    cout<<"Number of elements are : "<<sobj -> Count()<<"\n";

    sobj -> DeleteLast();

    sobj -> Display();
    cout<<"Number of elements are : "<<sobj -> Count()<<"\n";

    sobj -> DeleteFirst();

    sobj -> Display();
    cout<<"Number of elements are : "<<sobj -> Count()<<"\n";

    sobj -> InsertAtPos(105,4);

    sobj -> Display();
    cout<<"Number of elements are : "<<sobj -> Count()<<"\n";

    sobj -> DeleteAtPos(4);

    sobj -> Display();
    cout<<"Number of elements are : "<<sobj -> Count()<<"\n";

    delete sobj;

///////////////////////////////////////////////////////////////////////////////////////

    cout<<"\nDoubly Circular Linked list\n\n";
    DoublyCLL<int> *DCLLobj = new DoublyCLL<int>();

    DCLLobj -> InsertFirst(51);
    DCLLobj -> InsertFirst(21);
    DCLLobj -> InsertFirst(11);

    DCLLobj -> Display();

    cout<<"Number of nodes are : "<<DCLLobj -> Count()<<"\n";

    DCLLobj -> InsertLast(101);
    DCLLobj -> InsertLast(111);
    DCLLobj -> InsertLast(121);
    
    DCLLobj -> Display();

    cout<<"Number of nodes are : "<<DCLLobj -> Count()<<"\n";
    
    DCLLobj -> DeleteFirst();

    DCLLobj -> Display();
    cout<<"Number of nodes are : "<<DCLLobj -> Count()<<"\n";
    
    DCLLobj -> DeleteLast();

    DCLLobj -> Display();
    cout<<"Number of nodes are : "<<DCLLobj -> Count()<<"\n";
    
    DCLLobj -> InsertAtPos(105,4);

    DCLLobj -> Display();
    cout<<"Number of nodes are : "<<DCLLobj -> Count()<<"\n";
    
    DCLLobj -> DeleteAtPos(4);

    DCLLobj -> Display();
    cout<<"Number of nodes are : "<<DCLLobj -> Count()<<"\n";
    
    delete DCLLobj;

    return 0;
}