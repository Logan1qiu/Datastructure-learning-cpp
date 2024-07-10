#include <iostream>
#include <vector>
#include "helloworld.h"
using namespace std;

helloworld::helloworld()
{
}

helloworld::~helloworld()
{
}

void helloworld::printVector(vector<int> *myvector)
{
    for(auto it = myvector->begin(); it != myvector->end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void helloworld::printHello(void)
{
    cout << "hello";
}