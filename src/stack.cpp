#include <iostream>
#include <vector>
#include <algorithm>
#include "helloworld.h"
#include "stack.h"
using namespace std;

template <class T>
inline stack<T>::stack()
{
    this->head = new Node;
    head->next = NULL;
    this->length = 0;
}

template <class T>
stack<T>::~stack()
{
    delete head;
}

template <class T>
bool stack<T>::isEmpty()
{
    if (head->next == NULL || head == NULL)
    {
        return true;
    }
    else return false;
}

template <class T>
bool stack<T>::foreachStack()
{
    if (isEmpty())
    {
        cout << "Cannot foreach empty stack" << endl;
        return false;
    }
    Node *p = head;
    cout << "The stack is:";
    while (p->next != NULL)
    {
        p = p->next;
        cout << p->data;
    }
    cout << endl;
    return true;
}

template <class T>
int stack<T>::getLength()
{
    if (isEmpty())
    {
        return 0;
    }
    Node *p = head;
    int count = 0;
    while (p->next != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

template <class T>
bool stack<T>::push(T n)
{
    if (head == NULL)
    {
        return false;
    }
    Node *add = new Node;
    add->data = n;
    add->next = head->next;
    head->next = add;
    this->length++;
    return true;
}

template <class T>
T stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Cannot pop empty stack!!" << endl;
        return T();
    }
    Node *p = head->next;
    head->next = p->next;
    T preData = p->data;
    delete p;
    return preData;
}

template <class T>
bool stack<T>::deleteAll()
{
    while (!isEmpty())
    {
        this->pop();
    }
    
    return true;
}

template class stack<int>;