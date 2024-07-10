#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <queue>
#include <map>
using namespace std;

class Graph
{
private:
    int inf = 9999;
    char vex[100];
    int edge[100][100];
    int vexnum;
    int edgenum;

    typedef struct node
    {
        int name;
        int dist;
        int front;
    }node;

    bool inopen[100];
    bool inclose[100];
    
public:


    Graph(/* args */);
    ~Graph();

    vector<int> pathPlanning_dijkstra(int begin, int end);
    bool nodeInit(node &currentnode, int name, int dist, int front);
    int minKey(map<int,node> myset); //从集合中返回最小代价的键值
    bool searchNode(map<int,node> &openset,map<int,node> &closeset, node currentnode, int end);
};

Graph::Graph(/* args */)
{
    vex[0]='0';
    vex[1]='1';
    vex[2]='2';
    vex[3]='3';
    vex[4]='4';
    vexnum = 5;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (j == i)
            {
                edge[i][j]=0;
            }
            else edge[i][j] = inf;
        }
    }
    edge[0][1] = 10;
    edge[0][4] = 5;
    edge[1][2] = 1;
    edge[1][4] = 2;
    edge[2][3] = 4;
    edge[3][0] = 7;
    edge[3][2] = 6;
    edge[4][1] = 3;
    edge[4][2] = 9;
    edge[4][3] = 2; 
    edgenum = 10;
    for (int i = 0; i < 100; i++)
    {
        inopen[i] = false;
        inclose[i] = false;
    }
    
}

Graph::~Graph()
{
}

inline vector<int> Graph::pathPlanning_dijkstra(int begin, int end)
{
    vector<int> path;
    
    node currentNode;
    map<int,node> openset;
    map<int,node> closeset;

    nodeInit(currentNode, begin, 0, -1);
    openset.insert(pair<int, node>(begin, currentNode));
    this->inopen[begin] = true;

    while (1)
    {
        if (searchNode(openset, closeset, currentNode, end))//搜寻当前节点周围的节点，加入openset中
        {
            int minkey = minKey(openset); //找到当前openset中代价值最小的元素
            node closenode = openset[minkey];
            closeset.insert(pair<int, node>(minkey, closenode));
            inclose[minkey] = true;
            openset.erase(minkey);
            currentNode = closenode;
            if (minkey == end)
            {
                break;
            }
        }
        else break; //搜寻不到终点，退出循环
    }
    node reviewnode = closeset[end];
    while (reviewnode.front != -1) //从终点回溯到起点
    {
        path.insert(path.begin(), reviewnode.name);
        reviewnode = closeset[reviewnode.front];
    }
    path.insert(path.begin(), begin);
    return path;
}

inline bool Graph::nodeInit(node &mnode, int name, int dist, int front)
{
    mnode.name = name;
    mnode.dist = dist;
    mnode.front = front;
    return true;
}

inline int Graph::minKey(map<int,node> myset)
{
    map<int, node>::iterator iter;
    int mincost = 9999;
    int minkey;
    for (iter=myset.begin(); iter!=myset.end(); ++iter)
    {
        if (iter->second.dist < mincost)
        {
            mincost = iter->second.dist;
            minkey = iter->first;
        }
    }
    return minkey;
}

inline bool Graph::searchNode(map<int,node> &openset, map<int,node> &closeset, node currentnode, int end)
{
    int currenIndex = currentnode.name;
    for (int i = 0; i < vexnum; i++)
    {
        if (edge[currenIndex][i]>0 || edge[currenIndex][i]<this->inf)//遍历当前节点周围节点
        {
            int newdist = currentnode.dist+edge[currenIndex][i];
            if (inclose[i])//若节点被收录，则找下一个节点
            {
                continue;
            }
            if (inopen[i])//若节点被查询过，更新节点信息
            {
                if (newdist < openset[i].dist) //若新的距离更短，更新代价
                {
                    openset[i].dist = newdist;
                    openset[i].front = currenIndex;
                }
            }
            else//若节点没有被查询过，收录到openset中
            {
                node opennode;
                nodeInit(opennode, i, newdist, currenIndex);
                openset.insert(pair<int, node>(i, opennode));
                inopen[i] = true;
            }
        }
    }
    if (openset.empty())
    {
        cout << "没路了哥，到不了" <<endl;
        return false;
    }
    return true;
}
