#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T> class Queue
{
private:
    T *base;
    int MAXSIZE;
    int head;
    int tail;

public:
    Queue(int maxSize = 5);
    ~Queue();

    bool isEmpty();
    bool isFull();
    bool foreachQueue();
    int getLength();

    bool push(T data);
    T pop();
    bool deleteAll();
    T changeFromIndex(int index, T data);
    vector<int> changeFromValue(T pdata, T newdata);

    vector<int> getIndexFromValue(T data);
    T getValueFromIndex(int index);
};


