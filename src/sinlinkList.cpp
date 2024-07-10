#include <iostream>
#include <vector>
#include "helloworld.h"
#include "sinlinkList.h"
using namespace std;

sinlinkList::sinlinkList()
{
    head = new sinlinNode(0); //创建一个头节点对象，并在堆上分配内存空间
}

sinlinkList::~sinlinkList()
{
    delete head; //删除头节点
}

bool sinlinkList::isEmpty()
{
    if(head->next == NULL){
        return true;
    }
    else return false;
}

int sinlinkList::getLength()
{
    // if(this->isEmpty()){
    //     cout << "The list is empty!!!!!" << endl;
    // }
    int count = 0;
    sinlinNode *p = head->next;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

bool sinlinkList::foreachList()
{
    if(this->isEmpty()){
        cout << "The list is empty!!!!!" << endl;
        return false;
    }
    sinlinNode *p = head;
    while (p->next != NULL)
    {
        p = p->next;
        cout << p->data;
    }
    cout << endl;
    return true;
}

bool sinlinkList::insertHead(int data)
{
    sinlinNode *node = new sinlinNode(data);
    if(head == NULL){
        cout << "该链表缺失头链表";
        return false;
    }
    node->next = head->next;
    head->next = node;
    return true;
}

bool sinlinkList::insertBack(int data)
{
    int length = this->getLength();
    sinlinNode *node = new sinlinNode(data);
    sinlinNode *p = head;
    if(head == NULL){
        cout << "该链表缺失头链表";
        return false;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = node; 
    return true;
}

bool sinlinkList::insertMid(int n, int data)
{
    if(head == NULL){
        cout << "该链表缺失头节点" << endl;
        return false;
    }
    if (n<0 || n>this->getLength())
    {
        cout << "添加索引非法，该链表长度为：" << this->getLength() << endl;
        return false;
    }
    else{
        sinlinNode *node = new sinlinNode(data);
        sinlinNode *p = head;
        for (int i = 0; i < n; i++)
        {
            p = p->next;
        }
        node->next = p->next;
        p->next = node;
        return true;
    }
}

bool sinlinkList::insertList(string mode, int index, sinlinkList *list, int start, int end)
{
    if (head == NULL)
    {
        cout << "该链表缺失头节点" << endl;
        return false;
    }
    
    if (mode == "head")
    {
        for (int i = 0; i < end - start+1; i++)
        {
            this->insertMid(i, list->getData(start + i));
        }
    }
    else if (mode == "mid")
    {
        if (index<0 || index > this->getLength())
        {
            cout << "插入索引输入非法" << endl;
            return false;
        }
        for (int i = 0; i <end - start +1; i++)
        {
            this->insertMid(index + i, list->getData(start+i));
        }
    }
    else if (mode == "back")
    {
        for (int i = 0; i < end - start+1; i++)
        {
            this->insertBack(list->getData(start + i));
        }
    }
    else{
        cout << "插入模式名称错误"  << endl;
        return false;
    }
    return true;
}

bool sinlinkList::insertList(string mode, int index, sinlinkList *list)
{
    int addlength = list->getLength();
    if (head == NULL)
    {
        cout << "该链表缺失头节点" << endl;
        return false;
    }
    if (mode == "head")
    {
        for (int i = 0; i < addlength; i++)
        {
            this->insertMid(i, list->getData(i+1));
        }
    }
    else if (mode == "mid")
    {
        if (index<0 || index > this->getLength())
        {
            cout << "插入索引输入非法" << endl;
            return false;
        }
        for (int i = 0; i <addlength; i++)
        {
            this->insertMid(index + i, list->getData(i+1));
        }
    }
    else if (mode == "back")
    {
        for (int i = 0; i < addlength; i++)
        {
            this->insertBack(list->getData(i+1));
        }
    }
    else{
        cout << "插入模式名称错误"  << endl;
        return false;
    }
    return true;
}

bool sinlinkList::insertList(string mode, sinlinkList *list, int start, int end)
{
    if (head == NULL)
    {
        cout << "该链表缺失头节点" << endl;
        return false;
    }
    if (mode == "head")
    {
        for (int i = 0; i < end - start+1; i++)
        {
            this->insertMid(i, list->getData(start + i));
        }
    }
    else if (mode == "back")
    {
        for (int i = 0; i < end - start+1; i++)
        {
            this->insertBack(list->getData(start + i));
        }
        
    }
    else if (mode == "mid")
    {
        cout << "请输入插入位置" << endl;
        return false;
    }
    else{
        cout << "插入模式名称错误"  << endl;
        return false;
    }
    return true;
}

bool sinlinkList::insertList(string mode, sinlinkList *list)
{
    int addlength = list->getLength();
    if (head == NULL)
    {
        cout << "该链表缺失头节点" << endl;
        return false;
    }
    if (mode == "head")
    {
        for (int i = 0; i < addlength; i++)
        {
            this->insertMid(i, list->getData(i+1));
        }
    }
    else if (mode == "back")
    {
        for (int i = 0; i < addlength; i++)
        {
            this->insertBack(list->getData(i+1));
        }
        
    }
    else if (mode == "mid")
    {
        cout << "请输入插入位置" << endl;
        return false;
    }
    else{
        cout << "插入模式名称错误"  << endl;
        return false;
    }
    return true;
}

bool sinlinkList::insertFrontNode(sinlinNode *node)
{
    return false;
}

bool sinlinkList::insertBackNode(sinlinNode *node)
{
    return false;
}

int sinlinkList::deleteHead()
{
    if(this->isEmpty()){
        cout << "该链表为空链表" << endl;
        return 0;
    }
    sinlinNode *p = head;
    p = p->next;//需要删除的节点
    head->next = p->next; //头节点链接到删除后的那个节点
    int data = p->data; //存储删除节点的数据
    delete p; // 删除节点
    return data;
}

int sinlinkList::deleteBack()
{
    if(this->isEmpty()){
        cout << "该链表为空链表" << endl;
        return 0;
    }
    sinlinNode *p = head;
    sinlinNode *r = p; // 用于记录p的前一个节点
    while (p->next != NULL)
    {
        r = p;
        p = p->next;
    }
    r->next = NULL;
    int data = p->data;
    delete p;
    return data;
}

int sinlinkList::deleteMid(int n)
{
    if(this->isEmpty()){
        cout << "该链表为空链表" << endl;
        return 0;
    }
    if (n<1 || n>this->getLength())
    {
        cout << "删除索引非法" << endl;
        return 0;
    }
    else{
        sinlinNode *p = head;
        sinlinNode *r = p;
        for (int i = 0; i < n; i++)
        {
            r = p;
            p = p->next;
        }
        r->next = p->next;
        int data = p->data;
        delete p;
        return data;
    }
    
    return 0;
}

vector<int> sinlinkList::deleteMid(int start, int end)
{
    if(this->isEmpty()){
        cout << "该链表为空链表" << endl;
        return vector<int>();
    }
    if (start<1 || end<1 || start>this->getLength() || end>this->getLength() || start>end)
    {
        cout << "删除索引非法" << endl;
        return vector<int>();
    }
    else{
        sinlinNode *p = head;
        sinlinNode *r = p; //用于记录删除范围前的最后一个节点
        vector<int> dataset;
        int count = 0;
        while (count < start)
        {
            r = p;
            p = p->next;
            count++;
        }
        for (int i = 0; i < end - start+1; i++)
        {
            sinlinNode *q = p; //用于记录需要删除的节点
            p = p->next;
            dataset.push_back(q->data);
            delete q;
        }
        r->next = p; //链接断掉的两个节点
        return dataset;
    }
}

vector<int> sinlinkList::deleteNum(int data)
{
    if(this->isEmpty()){
        cout << "该链表为空链表" << endl;
        return vector<int>();
    }
    sinlinNode *p = head;
    sinlinNode *r = p; //记录删除前的节点
    vector<int> index;
    int length = this->getLength();
    for (int i = 0; i < length; i++)
    {
        if (p->data == data || i)
        {
            sinlinNode *q = p; //记录需要删除的节点
            index.push_back(i+1);
            r->next = p->next; //删除前的节点链接当前需要删除节点的下一个节点
            // r = p; // 此行代码不需要，因为r只记录删除前的节点，该节点会被删除，因此r不更新
            p = p->next;
            delete q;
        }
        else{
            r = p; //若不需要删除则r随着p更新
            p = p->next;
        }
    }
    return index;
}

bool sinlinkList::deleteAll()
{
    if(this->isEmpty()){
        cout << "该链表为空链表，无需删除" << endl;
        return false;
    }
    sinlinNode *p = head->next;
    sinlinNode *q = p;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
    head->next = NULL;
    return true;
}

int sinlinkList::changeIndex(int n, int data)
{
    if(this->isEmpty()){
        cout << "该链表为空链表，无法更改" << endl;
        return 0;
    }
    if (n<1 || n>this->getLength())
    {
        cout << "索引非法，无法更改" << endl;
        return 0;
    }
    else{
        int count = 0;
        sinlinNode *p = head;
        while (count < n)
        {
            p = p->next;
            count++;
        }
        int predata = p->data;
        p->data = data;
        return predata;
    }
}

vector<int> sinlinkList::changeNum(int pre, int now)
{
    if(this->isEmpty()){
        cout << "该链表为空链表，无法替换" << endl;
        return vector<int>();
    }
    vector<int> index = this->getIndexAll(pre); // 找到所有需要更改的索引
    if (index.size()) //如果有可以替换的值
    {
        for (auto it = index.begin(); it != index.end(); ++it) { //迭代遍历可替换的索引
            this->changeIndex(*it, now); //将数据替换成now
        }
        return index;
    }
    else{
        cout << "没有找到可以替换的值" << endl;
        return vector<int>();
    }
}

bool sinlinkList::changeList(int n, sinlinkList *list)
{
    if(this->isEmpty()){
        cout << "该链表为空链表，自动替换为新链表" << endl;
        this->insertList("back", list);
        return true;
    }
    int lengththis = this->getLength();
    int lengthlist = list->getLength();
    if (n<0 || n>lengththis)
    {
        cout << "索引值非法" << endl;
        return false;
    }
    if (lengththis - n +1 < lengthlist) // 若被替代链表剩余项不足
    {
        for (int i = 0; i < lengththis - n +1; i++) //先将被替代链表全部替代
        {
            this->changeIndex(n+i, list->getData(i+1));
        }
        this->insertList("back", list, lengththis-n+2, lengthlist);
        return true;
    }
    else{ //若被替代链表剩余项充足
        for (int i = 0; i < lengthlist; i++)
        {
            this->changeIndex(n+i, list->getData(i+1));
        }
        return true;
    }
    
    
    return false;
}

bool sinlinkList::revoverList(sinlinkList *list)
{
    this->deleteAll();
    this->insertList("back", list);
    return true;
}

int sinlinkList::getData(int n)
{
    if (head == NULL || n<1 || n>this->getLength())
    {
        cout << "查找操作非法" << endl;
        return 0;
    }
    else{
        sinlinNode *p = head;
        for (int i = 0; i < n; i++)
        {
            p = p->next;
        }
        return p->data;
    }
}

int sinlinkList::getIndex(int data)
{
    if (head == NULL)
    {
        cout << "该链表缺失头节点" << endl;
        return 0;
    }
    sinlinNode *p = head;
    int index = 0;
    while (p->data != data || index == 0)
    {
        index++;
        if (p->next == NULL)//链表遍历完了
        {
            index = 0;
            cout << "该链表中没有数据："<< data << endl;
            break;
        }
        p = p->next;
    }
    return index; //若返回值为0，则表示没有找到结果
}

vector<int> sinlinkList::getIndexAll(int data)
{
    if (head == NULL)
    {
        cout << "该链表缺失头节点" << endl;
        return vector<int>();
    }
    std::vector<int> index;
    sinlinNode *p = head;
    for (int i = 0; i <= this->getLength(); i++)
    {
        if (i != 0 && p->data == data)
        {
            index.push_back(i);
        }
        if (p->next == NULL) break;
        p = p->next;
    }
    if (index.size())
    {
        return index;
    }
    else{
        cout << "没有找到数据" << data << endl;
        return vector<int>();
    }
}

sinlinNode::sinlinNode(int n)
{
    data = n;
    next = NULL;
}

sinlinNode::~sinlinNode()
{
}
