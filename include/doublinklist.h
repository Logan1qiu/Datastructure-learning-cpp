#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class doubNode
{
private:
    
public:
    int data;
    doubNode *prio;
    doubNode *next;

    doubNode(int data); //构造一个节点
    ~doubNode();
};


class doublinklist
{
private:
    void qianchanode(doubNode *node, doubNode *addnode);
    void houchanode(doubNode *node, doubNode *addnode);
    void tailChange(doubNode *node, doubNode *addnode);
    bool isNodethere(doubNode *node);
    
    
public:
    doubNode *head;
    doubNode *tail;




    doublinklist(); //创建一个双链表
    ~doublinklist(); //析构一个双链表




    bool isEmpty(); //判断是否为空
    int getLength(); //获取双链表长度
    bool foreachList(string mode = "forward"); //遍历双链表
    // vector<int> getAllData(string mode);
    vector<doubNode*> getAllAdd(string mode);




    //增add
    bool insertFront(doubNode *node, int data); //前插（特定节点与插入数据）
    bool insertFront(doubNode *node, doubNode *addnode);//前插（特定节点与插入节点）
    bool insertFront(int index, int data);//前插（索引与插入数据）

    bool insertBack(doubNode *node, int data); //后插（特定节点与插入数据）
    bool insertBack(doubNode *node, doubNode *addnode);
    bool insertBack(int index, int data);

    bool insertHead(int data); //头插法
    bool insertHead(doubNode *node);
    bool insertTail(int data); //尾插法
    bool insertTail(doubNode *node); //尾插法

    bool insertListHead(doublinklist *list);
    bool insertListHead(doublinklist *list, int start, int end); //在链表中插入一个链表
    bool insertListTail(doublinklist *list);
    bool insertListTail(doublinklist *list, int start, int end);
    bool insertListMid(int index, doublinklist *list);
    bool insertListMid(int index, doublinklist *list, int start, int end);


    //删delete
    int deleteNode(doubNode *node);//删除当前节点
    int deleteNode(int index);
    int deleteFront(doubNode *node); //前删
    int deleteFront(int index);
    int deleteBack(doubNode *node); //后删
    int deleteBack(int index);
    int deleteHead(); //头删
    int deleteTail(); //尾删
    bool deleteAll(); //全部删除



    //改change
    int changeNode(doubNode *pre, int data); //更改节点数据
    int changeNode(doubNode *pre, doubNode *now); //以节点更改节点，返回更改前的数据
    int changeNode(int index, int data); //以索引的方式更改数据

    //查find
    int getData(int index);
    int getData(doubNode *node);
    doubNode* findNode(int index);
    doublinklist getPartlist(int start, int end); //根据索引截取一段返回新的list


};

