#include <iostream>
#include <vector>
#include <algorithm>
#include "sequence.h"
using namespace std;

template <class T>
inline Sequence<T>::Sequence()
{
    this->array = new T[initialSize];
    this->maxSize = initialSize;
    this->length = 0;
}

template <class T>
Sequence<T>::~Sequence()
{
    delete array;
}

template <class T>
bool Sequence<T>::isEmpty()
{
    if (this->length == 0)
    {
        return true;
    }
    return false;
}

template <class T>
int Sequence<T>::getLength()
{
    return this->length;
}

template <class T>
bool Sequence<T>::foreachSequence()
{
    if (this->length == 0)
    {
        cout << "The list is empty" << endl;
        return false;
    }
    cout << "The sequence list is:" << endl;
    for (int i = 0; i < this->length; i++)
    {
        cout << array[i];
    }
    cout << endl;
    return true;
}

template <class T>
bool Sequence<T>::extendSequence(int addlength)
{
    T *p = this->array;
    this->array = new T[this->maxSize + addlength];
    for (int i = 0; i < this->length; i++)
    {
        this->array[i] = p[i];
    }
    this->maxSize = this->maxSize + addlength;
    delete p;
    return true;
}

template <class T>
bool Sequence<T>::shortenSequence(int minlength)
{
    T *p = this->array;
    this->array = new T[this->maxSize - minlength];
    for (int i = 0; i < this->length; i++)
    {
        this->array[i] = p[i];
    }
    this->maxSize = this->maxSize - minlength;
    delete p;
    return true;
}

template <class T>
T Sequence<T>::findElement(int index)
{
    if (isEmpty())
    {
        cout << "is empty";
        return T();
    }
    if (index<1 || index > this->length)
    {
        cout << "The index is valid" << endl;
        return T();
    }
    return this->array[index-1];
}

template <class T>
bool Sequence<T>::insertBack(int index, T data)
{
    if (index<0 || index > this->length)
    {
        cout << "The index is valid" << endl;
        return false;
    }
    if (this->length == this->maxSize ) //The array is not enough
    {
        this->extendSequence(1);
    }
    for (int i = this->length; i > index; i--)
    {
        this->array[i] = this->array[i-1];
    }
    this->array[index] = data;
    this->length++;
    return true;
}

template <class T>
bool Sequence<T>::insertFront(int index, T data)
{
    if (index <1 || index > this->length)
    {
        cout << "The index is valid" << endl;
        return false;
    }
    if (this->length == this->maxSize ) //The array is not enough
    {
        this->extendSequence(1);
    }
    for (int i = this->length; i >= index; i--)
    {
        this->array[i] = this->array[i-1];
    }
    this->array[index-1] = data;
    this->length++;
    return true;
}

template <class T>
T Sequence<T>::deleteFrom_index(int index)
{
    if (isEmpty())
    {
        cout << "cannot delete empty list" << endl;
        return T();
    }
    if (index<1 || index > this->length)
    {
        cout << "the index is valid" << endl;
        return T();
    }
    T saveDate = this->array[index-1];
    for (int i = index; i < this->length; i++)
    {
        this->array[i-1] = this->array[i]; 
    }
    this->length--;
    if (this->maxSize - this->length > 0)
    {
        this->shortenSequence(this->maxSize - this->length);
    }
    return saveDate;
}

template <class T>
T Sequence<T>::changeData(int index, T data)
{
    if (index < 0 || index > this->length)
    {
        cout << "the index is valid" << endl;
        return T();
    }
    T saveData = this->array[index -1];
    this->array[index -1] = data;
    return saveData;
}

template <class T>
bool Sequence<T>::deleteAll()
{
    if (isEmpty())
    {
        cout << "cannot delete empty list" << endl;
        return false;
    }

    return true;
}


template class Sequence<int>;