#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



template <class T> class Sequence
{
private:
    T *array;
    int initialSize = 1;
    int maxSize;
    int length;

    bool extendSequence(int addlength);
    bool shortenSequence(int minlength);

public:
    Sequence(/* args */);
    ~Sequence();

    bool isEmpty();
    int getLength();
    bool foreachSequence();
    

    T findElement(int index);
    bool insertBack(int index, T data);
    bool insertFront(int index, T data);
    T deleteFrom_index(int index);
    T changeData(int index, T data);
    bool deleteAll();
    
};

