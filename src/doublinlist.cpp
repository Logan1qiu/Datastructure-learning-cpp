#include <iostream>
#include <vector>
#include <algorithm>
#include "helloworld.h"
#include "sinlinkList.h"
#include "doublinklist.h"
using namespace std;

doubNode::doubNode(int data)
{
    this->prio = NULL;
    this->next = NULL;
    this->data = data;
}

doubNode::~doubNode()
{
}

void doublinklist::qianchanode(doubNode *node, doubNode *addnode)
{
    addnode->prio = node->prio;
    node->prio->next = addnode;
    node->prio = addnode;
    addnode->next = node;
}

void doublinklist::houchanode(doubNode *node, doubNode *addnode)
{
    addnode->next = node->next;
    if (node->next != NULL)
    {
        node->next->prio = addnode;
    }
    else tailChange(node, addnode);
    addnode->prio = node;
    node->next = addnode;
}

void doublinklist::tailChange(doubNode *node, doubNode *addnode)
{
    if (node->next == NULL)//当前节点为尾节点
    {
        this->tail = addnode;
    }
}

bool doublinklist::isNodethere(doubNode *node)
{
    std::vector<doubNode*> addvector = this->getAllAdd("forward"); //找到所有节点
    if (std::find(addvector.begin(), addvector.end(), node) != addvector.end()) //判断该节点是否在其中
    {
        return true;
    }
    else return false;
}


doublinklist::doublinklist()
{
    this->head = new doubNode(0);
    this->tail = this->head;
}

doublinklist::~doublinklist()
{
}

bool doublinklist::isEmpty()
{
    if (head->next == NULL)
    {
        cout << "The doublist is empty" << endl;
        return true;
    }
    else return false;
}

int doublinklist::getLength()
{
    int count = 0;
    doubNode *p = head->next;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

bool doublinklist::foreachList(string mode)
{
    if (this->isEmpty())
    {
        cout << "Cannot foreach the empty doublist" << endl;
        return false;
    }
    if (mode == "forward")
    {
        doubNode *p = this->head;
        while (p->next != NULL)
        {
            p = p->next;
            cout << p->data;
        }
    }
    else if (mode == "backward")
    {
        doubNode *p = this->tail;
        while (p != this->head)
        {
            cout << p->data;
            p = p->prio;
        }
    }
    cout << endl;
    return true;
}

vector<doubNode *> doublinklist::getAllAdd(string mode)
{
    std::vector<doubNode*> myvector;
    if (mode == "forward")
    {
        doubNode *p = head;
        myvector.push_back(p);
        while (p->next != NULL)
        {
            p = p->next;
            myvector.push_back(p);
        }
    }
    else if (mode == "backward")
    {
        doubNode *q = tail;
        while (q != head)
        {
            q = q->prio;
            myvector.push_back(q);
        }
    }
    else
    {
        cout << "mode is wrong" << endl;
        return vector<doubNode *>();
    }
    return myvector;
}

bool doublinklist::insertFront(doubNode *node, int data)
{
    if (this->head == NULL)
    {
        cout << "fail with no head" << endl;
        return false;
    }
    if (node == NULL || node == head || !isNodethere(node))
    {
        cout << "The node is illegal" << endl;
        return false;
    }
    doubNode *addnode = new doubNode(data);
    qianchanode(node, addnode);
    return true;
}

bool doublinklist::insertFront(doubNode *node, doubNode *addnode)
{
    if (this->head == NULL)
    {
        cout << "fail with no head" << endl;
        return false;
    }
    if (node == NULL || node == head || addnode == head || !isNodethere(node))
    {
        cout << "The node is illegal" << endl;
        return false;
    }
    qianchanode(node, addnode);
    return true;
}

bool doublinklist::insertFront(int index, int data)
{
    if (this->head == NULL)
    {
        cout << "Cannot insert without headnode" << endl;
        return false;
    }
    this->insertFront(this->findNode(index), data);
    return true;
}

bool doublinklist::insertBack(doubNode *node, int data)
{
    if (this->head == NULL)
    {
        cout << "Cannot insert without headnode" << endl;
        return false;
    }
    if (node == NULL || !isNodethere(node))
    {
        cout << "The node is illegal" << endl;
        return false;
    }
    doubNode *addnode = new doubNode(data);
    houchanode(node, addnode);
    return true;
}

bool doublinklist::insertBack(doubNode *node, doubNode *addnode)
{
    if (this->head == NULL)
    {
        cout << "fail with no head" << endl;
        return false;
    }
    if (node == NULL || addnode == head || !isNodethere(node))
    {
        cout << "The node is illegal" << endl;
        return false;
    }
    houchanode(node, addnode);
    return true;
}

bool doublinklist::insertBack(int index, int data)
{
    if (this->head == NULL)
    {
        cout << "Cannot insert without headnode" << endl;
        return false;
    }
    this->insertBack(this->findNode(index), data);
    return true;
}

bool doublinklist::insertHead(int data)
{
    if (this->head == NULL)
    {
        cout << "Cannot insert without headnode" << endl;
        return false;
    }
    doubNode *node = new doubNode(data);
    this->insertBack(head, node);
    return true;
}

bool doublinklist::insertHead(doubNode *node)
{
    if (this->head == NULL)
    {
        cout << "Cannot insert without headnode" << endl;
        return false;
    }
    this->insertBack(head, node);
    return true;
}

bool doublinklist::insertTail(int data)
{
    if (this->head == NULL)
    {
        cout << "Cannot insert without headnode" << endl;
        return false;
    }
    doubNode *node = new doubNode(data);
    this->insertBack(tail, node);
    return true;
}

bool doublinklist::insertTail(doubNode *node)
{
    if (this->head == NULL)
    {
        cout << "Cannot insert without headnode" << endl;
        return false;
    }
    this->insertBack(tail, node);
    return true;
}

bool doublinklist::insertListHead(doublinklist *list)
{
    if (list->isEmpty())
    {
        return false;
    }
    this->insertListHead(list, 1, list->getLength());
    return true;
}

bool doublinklist::insertListHead(doublinklist *list, int start, int end)
{
    if (list->isEmpty() || start > end)
    {
        return false;
    }
    for (int i = 0; i < end-start+1; i++)
    {
        this->insertBack(i, list->getData(start+i));
    }
    return true;
}

bool doublinklist::insertListTail(doublinklist *list)
{
    if (list->isEmpty())
    {
        return false;
    }
    this->insertListTail(list, 1, list->getLength());
    return true;
}

bool doublinklist::insertListTail(doublinklist *list, int start, int end)
{
    if (list->isEmpty() || start > end)
    {
        return false;
    }
    for (int i = 0; i < end-start+1; i++)
    {
        this->insertTail(list->getData(start+i));
    }
    return true;
}

bool doublinklist::insertListMid(int index, doublinklist *list)
{
    if (list->isEmpty())
    {
        return false;
    }
    this->insertListMid(index, list, 1, list->getLength());
    return true;
}

bool doublinklist::insertListMid(int index, doublinklist *list, int start, int end)
{
    if (list->isEmpty() || start > end)
    {
        return false;
    }
    for (int i = 0; i < end-start+1; i++)
    {
        this->insertBack(i+index, list->getData(start+i));
    }
    return true;
}

int doublinklist::deleteNode(doubNode *node)
{
    if (this->isEmpty())
    {
        cout << "cannot delete data in empty list" << endl;
        return 0;
    }
    if (node == NULL|| node == head || !isNodethere(node))
    {
        cout << "The node is illegal" << endl;
        return 0;
    }
    node->prio->next = node->next;
    if (node->next != NULL) //如果这个节点不是最后一个节点
    {
        node->next->prio = node->prio;
    }
    else this->tail = node->prio; //如果是最后一个节点，则需要更改表尾指针
    int data = node->data;
    delete node;
    return data;
}

int doublinklist::deleteNode(int index)
{
    return this->deleteNode(this->findNode(index));
}

int doublinklist::deleteFront(doubNode *node)
{
    return this->deleteNode(node->prio);
}

int doublinklist::deleteFront(int index)
{
    return this->deleteFront(this->findNode(index));
}

int doublinklist::deleteBack(doubNode *node)
{
    return this->deleteNode(node->next);
}

int doublinklist::deleteBack(int index)
{
    return this->deleteBack(this->findNode(index));
}

int doublinklist::deleteHead()
{
    return this->deleteBack(this->head);
}

int doublinklist::deleteTail()
{
    return this->deleteNode(tail);
}

bool doublinklist::deleteAll()
{
    if (this->isEmpty())
    {
        cout << "cannot delete empty list" << endl;
        return false;
    }
    doubNode *p = head->next;
    doubNode *r = p;
    while (p != NULL)
    {
        r = p;
        p = p->next;
        delete r;
    }
    head->next = NULL;
    return true;
}

int doublinklist::changeNode(doubNode *pre, int data)
{
    if (!isNodethere(pre) || pre == head) //如果节点不存在
    {
        cout << "需要更改的节点不存在" << endl;
        return 0;
    }
    int predata = pre->data;
    pre->data = data;
    return predata;
}

int doublinklist::changeNode(doubNode *pre, doubNode *now)
{
    if (!isNodethere(pre) || pre == head || !isNodethere(now) || now == head)
    {
        cout << "输入的更改节点非法" << endl;
        return 0;
    }
    return this->changeNode(pre, now->data);
}

int doublinklist::changeNode(int index, int data)
{
    return this->changeNode(this->findNode(index), data);
}

int doublinklist::getData(int index)
{
    if (this->isEmpty())
    {
        cout << "cannot find data in empty list" << endl;
        return 0;
    }
    // int length = this->getLength();
    if (index<1 || index > this->getLength())
    {
        cout << "index is illigle" << endl;
        return 0;
    }
    doubNode *p = head;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }
    return p->data;
}

int doublinklist::getData(doubNode *node)
{
    if (this->isEmpty())
    {
        cout << "cannot find data in empty list" << endl;
        return 0;
    }
    if (node == NULL || !isNodethere(node))
    {
        cout << "The node is illegal" << endl;
        return 0;
    }
    return node->data;
}

doubNode *doublinklist::findNode(int index)
{
    if (this->isEmpty())
    {
        cout << "cannot find node in empty list" << endl;
        return nullptr;
    }
    if (index<0 || index > this->getLength())
    {
        cout << "index is illigle" << endl;
        return nullptr;
    }
    doubNode *p = head;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }
    return p;
}


doublinklist doublinklist::getPartlist(int start, int end)
{
    doubNode *p = this->findNode(start);
    doubNode *q = this->findNode(end);
    if (!isNodethere(p) || !isNodethere(q) || end < start)
    {
        cout << "index is illegel" << endl;
        return doublinklist();
    }
    doublinklist *newlist = new doublinklist;
    while (p != q->next)
    {
        newlist->insertTail(p->data);
        p = p->next;
    }
    return *newlist;
}
