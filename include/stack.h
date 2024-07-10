#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T> class stack
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *head;
    int length;

public:
    stack(/* args */);
    ~stack();


    bool isEmpty(); //判空
    bool foreachStack();
    int getLength();

    bool push(T n); //入栈
    T pop(); //出栈
    bool deleteAll();
};


