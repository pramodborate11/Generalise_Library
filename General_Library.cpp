///////////////////////////////////////////////////////////////////////////////////////
////////////////////Genearized Data Structure Liabrary/////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

/*---------------------------------------------------------------------------------------------------|
    Type                Name of Class For Node                      Name of class for functionality  |
-----------------------------------------------------------------------------------------------------|

    Singly Linear        SinglyLLLnode                                     SinglyLLL           Done

    Singly Circular      SinglyCLLnode                                     SinglyCLL           Done

    Doubly Linear        DoublyLLLnode                                     DoublyLLL           Done

    Doubly Circular      DoublyCLLnode                                     DoublyCLL           Done

-------------------------------------------------------------------------------------------------------
*/
#include <iostream>
using namespace std;

#pragma pack(1)

/////////////////////////////////////////////////////////////////////////////
//           Singly Linear Linked List using Generic Approach              //
/////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLLLnode
{
public:
    T data;
    SinglyLLLnode<T> *next;

    SinglyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template <class T>
class SinglyLLL
{
private:
    SinglyLLLnode<T> *first;
    int iCount;

public:
    SinglyLLL();

    void InsertFirst(T);

    void InsertLast(T);

    void DeleteFirst();

    void DeleteLast();

    void Display();

    int Count();

    void InsertAtPos(T, int);

    void DeleteAtPos(int);
};

template <class T>
SinglyLLL<T>::SinglyLLL()
{
    cout << "Object of SinglyLLL gets Created..\n";
    this->first = NULL;
    this->iCount = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertFirst
//      Input:              Data of node
//      Output:             Nothing
//      Description:        Use to node at first position
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertFirst(T no)
{
    SinglyLLLnode<T> *newn = NULL;
    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertLast
//      Input:              Data of node
//      Output:             Nothing
//      Description:        Use to node at last position
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    SinglyLLLnode<T> *newn = NULL;
    SinglyLLLnode<T> *temp = NULL;
    newn = new SinglyLLLnode<T>(no);

    if (this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    this->iCount++;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteFirst
//      Input:              Nothing
//      Output:             Nothing
//      Description:        To Delete the first node
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    SinglyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
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
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Deletelast
//      Input:              Nothing
//      Output:             Nothing
//      Description:        To Delete the last node
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteLast()
{
    SinglyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Display
//      Input:              Nothing
//      Output:             Nothing
//      Description:        Do Display the each node of linked list
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::Display()
{
    int iCnt = 0;
    SinglyLLLnode<T> *temp = NULL;
    temp = this->first;
    for (iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    }
    cout << "NULL\n";
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Count
//      Input:              Nothing
//      Output:             No.of Nodes(int)
//      Description:        Do return the no. of nodes
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLLL<T>::Count()
{
    return this->iCount;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertAtPos
//      Input:              Data of node
//      Output:             Nothing
//      Description:        Use to add the node at entered position if valid
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> *temp = NULL;
    SinglyLLLnode<T> *newn = NULL;
    int i = 0;
    if (pos < 1 || pos > this->iCount + 1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        this->InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);
        temp = this->first;

        for (i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteAtPos
//      Input:              Nothing
//      Output:             Nothing
//      Description:        To Delete the node from entered position if valid 
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> *temp = NULL;
    SinglyLLLnode<T> *target = NULL;
    int i = 0;
    if (pos < 1 || pos > this->iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        this->DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        for (i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        this->iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////
//          Singly Circular Linked List using Generic Approach             //
/////////////////////////////////////////////////////////////////////////////


template <class T>
class SinglyCLLnode
{
public:
    T data;
    SinglyCLLnode<T> *next;

    SinglyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template <class T>
class SinglyCLL
{
private:
    SinglyCLLnode<T> *first;
    SinglyCLLnode<T> *last;
    int iCount;

public:
    SinglyCLL();

    void InsertFirst(T);
    void InsertLast(T);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T, int);
    void DeleteAtPos(int);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout << "Object of SinglyCLL gets Created..\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertFirst
//      Input:              Data of node
//      Output:             Nothing
//      Description:        Use to node at first position
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;
    newn = new SinglyCLLnode<T>(no);

    if (this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
        newn->next = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
        this->last->next = this->first;
    }
    this->iCount++;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertLast
//      Input:              Data of node
//      Output:             Nothing
//      Description:        Use to node at last position
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> *newn = NULL;
    SinglyCLLnode<T> *temp = NULL;
    newn = new SinglyCLLnode<T>(no);

    if (this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
        newn->next = this->first;
    }
    else if (this->first->next == this->first)
    {
        this->first->next = newn;
        newn->next = this->first;
        this->last = newn;
    }
    else
    {
        int i = 0;
        temp = this->first;
        for (i = 1; i < this->iCount; i++)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->next = this->first;
        this->last = newn;
    }
    this->iCount++;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteFirst
//      Input:              Nothing
//      Output:             Nothing
//      Description:        To Delete the first node
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    SinglyCLLnode<T> *temp = NULL;

    if (this->first == NULL && this->last == NULL)
    {
        cout << "Linked is already Empty\n";
        return;
    }
    else if (this->first->next == this->first)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
        this->iCount--;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
        this->last->next = this->first;
        this->iCount--;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteLast
//      Input:              Nothing
//      Output:             Nothing
//      Description:        To Delete the Last node
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> *temp = NULL;

    if (this->first == NULL && this->last == NULL)
    {
        cout << "Linked List is Already Empty\n";
        return;
    }
    else if (this->first->next == this->first)
    {
        delete this->last;
        this->first = NULL;
        this->last = NULL;
        this->iCount--;
    }
    else
    {
        temp = this->first;
        while (temp->next->next != this->first)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = this->first;
        this->iCount--;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Display
//      Input:              Nothing
//      Output:             Nothing
//      Description:        Do Display the each node of linked list
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::Display()
{
    int iCnt = 0;
    SinglyCLLnode<T> *temp = NULL;
    temp = this->first;
    for (iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    }
    cout << "\n";
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Count
//      Input:              Nothing
//      Output:             No.of Nodes(int)
//      Description:        Do return the no. of nodes
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCLL<T>::Count()
{
    return this->iCount;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertAtPos
//      Input:              Data of node
//      Output:             Nothing
//      Description:        Use to add the node at entered position if valid
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *newn = NULL;
    int i = 0;

    if (pos < 1 || pos > this->iCount + 1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        this->InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);
        temp = this->first;

        for (i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteAtPos
//      Input:              Nothing
//      Output:             Nothing
//      Description:        To Delete the node from entered position if valid 
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *target = NULL;
    int i = 0;

    if (pos < 1 || pos > this->iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        this->DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        for (i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        this->iCount--;
    }
}
/////////////////////////////////////////////////////////////////////////////
//           Doubly Linear Linked List using Generic Approach              //
/////////////////////////////////////////////////////////////////////////////



template <class T>
class DoublyLLLnode
{
public:
    T data;
    DoublyLLLnode<T> *next;
    DoublyLLLnode<T> *prev;

    DoublyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyLLL
{
private:
    DoublyLLLnode<T> *first;
    int iCount;

public:
    DoublyLLL();

    void InsertFirst(T);

    void InsertLast(T);

    void InsertAtPos(T, int);

    void DeleteFirst();

    void DeleteLast();

    void DeleteAtPos(int);

    void Display();

    int Count();
};

template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout << "Linked List Get Created\n";
    this->first = NULL;
    this->iCount = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertFirst
//      Input:              Data of node
//      Output:             Nothing
//      Description:        Use to node at first position
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    newn = new DoublyLLLnode<T>(no);

    if (this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertLast
//      Input:              Data of node
//      Output:             Nothing
//      Description:        Use to node at last position
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;
    newn = new DoublyLLLnode<T>(no);

    if (this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertAtPos
//      Input:              Data of node
//      Output:             Nothing
//      Description:        Use to add the node at entered position if valid
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    int iCnt = 0;
    if (pos < 1 || pos > this->iCount + 1)
    {
        cout << "Invalid Position\n";
        return;
    }
    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        InsertLast(no);
    }
    else
    {

        newn = new DoublyLLLnode<T>(no);

        temp = this->first;
        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteFirst
//      Input:              Nothing
//      Output:             Nothing
//      Description:        To Delete the first node
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    if (this->first == NULL)
    {
        cout << "Linked is already empty\n";
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }
    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteLast
//      Input:              Nothing
//      Output:             Nothing
//      Description:        To Delete the last node
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;
    if (this->first == NULL)
    {
        cout << "Linked is already empty\n";
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteAtPos
//      Input:              Nothing
//      Output:             Nothing
//      Description:        To Delete the node from entered position if valid 
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;
    if (pos < 1 || pos > this->iCount)
    {
        cout << "Invalid Position\n";
        return;
    }
    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;
        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Display
//      Input:              Nothing
//      Output:             Nothing
//      Description:        Do Display the each node of linked list
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::Display()
{
    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    cout << "\nNULL<=>";
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|<=>";
        temp = temp->next;
    }
    cout << "NULL\n";
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Count
//      Input:              Nothing
//      Output:             No.of Nodes(int)
//      Description:        Do return the no. of nodes
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyLLL<T>::Count()
{
    return this->iCount;
}
/////////////////////////////////////////////////////////////////////////////
//           Doubly Circular Linked List using Generic Approach            //
/////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCLLnode
{
public:
    T data;
    DoublyCLLnode<T> *next;
    DoublyCLLnode<T> *prev;

    DoublyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyCLL
{
private:
    DoublyCLLnode<T> *first;
    DoublyCLLnode<T> *last;
    int iCount;

public:
    DoublyCLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    cout << "Object of DoublyCL gets Created..\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertFirst
//      Input:              Data of node
//      Output:             Nothing
//      Description:        Use to node at first position
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    newn = new DoublyCLLnode<T>(no);

    if (this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
        this->last->next = this->first;
        this->first->prev = this->last;
    }
    else
    {
        this->first->prev = newn;

        newn->next = this->first;
        newn->prev = this->last;
        this->first = newn;
        this->last->next = this->first;
    }
    this->iCount++;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertLast
//      Input:              Data of node
//      Output:             Nothing
//      Description:        Use to node at last position
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    newn = new DoublyCLLnode<T>(no);

    if (this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
        this->last->next = this->first;
        this->first->prev = this->last;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
        this->last->next = this->first;
    }
    this->iCount++;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertAtPos
//      Input:              Data of node
//      Output:             Nothing
//      Description:        Use to add the node at entered position if valid
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    int i = 0;
    DoublyCLLnode<T> *newn = NULL;
    DoublyCLLnode<T> *temp = NULL;
    if (pos < 1 || pos > this->iCount + 1)
    {
        cout << "Invalid Position";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        temp = this->first;
        newn = new DoublyCLLnode<T>(no);

        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        newn->next = temp->next;
        temp->next = newn;
        newn->next->prev = newn;
        this->iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteFirst
//      Input:              Nothing
//      Output:             Nothing
//      Description:        To Delete the first node
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if (this->first == NULL && this->last == NULL)
    {
        cout << "Linked list is empty\n";
        return;
    }

    if (this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }

    else
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = this->last;
    }
    this->iCount--;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteLast
//      Input:              Nothing
//      Output:             Nothing
//      Description:        To Delete the last node
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if (this->first == NULL && this->last == NULL)
    {
        cout << "Linked list is empty\n";
        return;
    }

    if (this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;
        this->last->next = this->first;
    }
    this->iCount--;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteAtPos
//      Input:              Nothing
//      Output:             Nothing
//      Description:        To Delete the node from entered position if valid 
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    int i = 0;
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *target = NULL;
    if (pos < 1 || pos > this->iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete target;
        this->iCount--;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Display
//      Input:              Nothing
//      Output:             Nothing
//      Description:        Do Display the each node of linked list
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::Display()
{
    int iCnt = 0;
    DoublyCLLnode<T> *temp = NULL;
    temp = this->first;
    for (iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout << "|" << temp->data << "|=>";
        temp = temp->next;
    }
    cout << "\n";
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Count
//      Input:              Nothing
//      Output:             No.of Nodes(int)
//      Description:        Do return the no. of nodes
//      Author:             Borate Pramod Khandu
//      Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////////////////////
//                               End Of Liabrary                                     //
///////////////////////////////////////////////////////////////////////////////////////
int main()
{

    return 0;
}