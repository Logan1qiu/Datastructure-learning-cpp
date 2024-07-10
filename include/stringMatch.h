#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class stringMatch
{
private:
    /* data */
public:
    stringMatch(/* args */);
    ~stringMatch();

    static int matchBF(string parent, string child);
    static int matchKMP(string parent, string child);
};


