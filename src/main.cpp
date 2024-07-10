#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <queue>
#include "helloworld.h"
#include "sinlinkList.h"
#include "doublinklist.h"
#include "main.h"
#include "stack.h"
#include "sequence.h"
#include "queue.h"
#include "stringMatch.h"
#include "BiTree.h"
#include "Graph.h"
using namespace std;

helloworld h;

int main() 
{
    helloworld h;
    Graph mygraph;
    vector<int> path = mygraph.pathPlanning_dijkstra(4,2);
    h.printVector(&path);
}
