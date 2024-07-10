#include <iostream>
#include <vector>
using namespace std;


class sinlinNode
{
private:
    
public:
    int data;
    sinlinNode *next;
    sinlinNode(int n); //创建一个节点
    ~sinlinNode(); //析构一个节点

    

};

class sinlinkList
{
private:
    
public:
    sinlinNode *head;
    int size;
    sinlinkList(); //构建一个单链表
    ~sinlinkList(); //析构一个单链表

    bool isEmpty(); //判断是否为空
    int getLength(); //获取单链表长度
    bool foreachList(); //遍历单链表


    bool insertHead(int data); //头插法
    bool insertBack(int data); //尾插法
    bool insertMid(int n, int data); //指定位置后插入
    bool insertList(string mode, int index, sinlinkList *list, int start, int end); //在链表中插入一个链表
    bool insertList(string mode, int index, sinlinkList *list);
    bool insertList(string mode, sinlinkList *list, int start, int end);
    bool insertList(string mode, sinlinkList *list);
    bool insertFrontNode(sinlinNode *node); //在指定节点前插入
    bool insertBackNode(sinlinNode *node); //在指定节点后插入

    int deleteHead(); //从头部删除数据
    int deleteBack(); //从尾部删除数据
    int deleteMid(int n); //通过索引删除数据
    vector<int> deleteMid(int start, int end); //删除一个范围的数据，并返回删除了哪些数据
    vector<int> deleteNum(int data); //删除所有指定数据并返回他们之前的位置
    bool deleteAll();// 删除所有数据，仅保留头节点

    int changeIndex(int n, int data); //更改指定索引的数据，并返回更改前的数据
    vector<int> changeNum(int pre, int now); //替换数据，并返回替换的索引
    bool changeList(int n, sinlinkList *list); //从指定索引往后，用新的链表替换
    bool revoverList(sinlinkList *list); //链表赋值（用外部链表数据覆盖该链表）

    int getData(int n); //查找对应索引的数据
    int getIndex(int data); //查找数据对应的索引，若索引为0，则表示没有找到结果
    vector<int> getIndexAll(int data); // 查找数据对应的所有索引


    
    

    
};



