#include <iostream>
#include <vector>
#include <algorithm>
#include "stringMatch.h"
using namespace std;


stringMatch::stringMatch(/* args */)
{
}

stringMatch::~stringMatch()
{
}

int stringMatch::matchBF(string parent, string child)
{
    int lenParent = parent.length();
    int lenChild = child.length();
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < lenParent && j < lenChild)
    {
        if (child[j] == parent[i])
        {
            i++;
            j++;
        }
        else
        {
            count++;
            i = count;
            j = 0;
        }
    }
    if (j == lenChild)
    {
        return i-j;
    }
    else
    {
        return -1;
    }
}

int stringMatch::matchKMP(string parent, string child)
{
    return 0;
}
