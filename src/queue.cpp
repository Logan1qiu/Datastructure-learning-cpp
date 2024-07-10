#include <iostream>
#include <vector>
#include <algorithm>
#include "queue.h"
using namespace std;

template <class T>
inline Queue<T>::Queue(int maxSize)
{
    this->base = new T[maxSize+1];
    this->MAXSIZE = maxSize+1;
    this->head = 0;
    this->tail = 0;
}

template <class T>
Queue<T>::~Queue()
{
    delete base;
}

template <class T>
bool Queue<T>::isEmpty()
{
    if (this->head == this->tail)
    {
        return true;
    }  
    return false;
}

template <class T>
bool Queue<T>::isFull()
{
    if ((this->tail+1)%this->MAXSIZE == this->head)
    {
        return true;
    }
    return false;
}

template <class T>
bool Queue<T>::foreachQueue()
{
    if (isEmpty())
    {
        cout << "cannot foreach empty queue" << endl;
        return false;
    }
    cout << "the queue is :";
    for (int i = this->head; i < this->tail; i++)
    {
        cout << this->base[i];
    }
    cout << endl;
    return true;
}

template <class T>
int Queue<T>::getLength()
{   
    return this->tail - this->head;
}

template <class T>
bool Queue<T>::push(T data)
{
    if (isFull())
    {
        cout << "cannnot add into full queue" << endl;
        return false;
    }
    this->base[this->tail] = data;
    this->tail = (this->tail+1)%this->MAXSIZE;
    return true;
}

template <class T>
T Queue<T>::pop()
{
    if (isEmpty())
    {
        cout << "cannnot pop empty queue" << endl;
        return T();
    }
    T savedata = this->base[this->head];
    this->head = (this->head+1)%this->MAXSIZE;
    return savedata;
}

template <class T>
bool Queue<T>::deleteAll()
{
    this->head = 0;
    this->tail = 0;
    return true;
}

template <class T>
T Queue<T>::changeFromIndex(int index, T data)
{
    if (isEmpty())
    {
        cout << "cannnot change empty queue" << endl;
        return T();
    }
    if (index<1 || index > this->getLength())
    {
        cout << "the index is valid" << endl;
        return T();
    }
    T predata = this->base[this->head+index-1];
    this->base[this->head+index-1] = data;
    return predata;
}

template <class T>
vector<int> Queue<T>::changeFromValue(T pdata, T newdata)
{
    if (isEmpty())
    {
        cout << "cannot change in empty queue" << endl;
        return vector<int>();
    }
    std::vector<int> indexs = this->getIndexFromValue(pdata);
    for (auto iter = indexs.begin(); iter != indexs.end(); iter++)
    {
        this->changeFromIndex(*iter, newdata);
    }
    return indexs;
}

template <class T>
vector<int> Queue<T>::getIndexFromValue(T data)
{
    if (isEmpty())
    {
        cout << "cannot find in empty queue" << endl;
        return vector<int>();
    }
    std::vector<int> myvector;
    for (int i = 0; i < this->getLength(); i++)
    {
        if (this->base[this->head+i] == data)
        {
            myvector.push_back(i+1);
        }
    }
    return myvector;
}

template <class T>
T Queue<T>::getValueFromIndex(int index)
{
    if (isEmpty())
    {
        cout << "cannot find in empty queue" << endl;
        return T();
    }
   return this->base[this->head+index-1];
}

template class Queue<int>;