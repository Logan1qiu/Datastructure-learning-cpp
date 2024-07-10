#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <queue>
#include "BiTree.h"
using namespace std;

bool isBiTreeEmpty(BiTree T)
{
    if (T == NULL)
    {
        return true;
    }
    return false;
}

bool visit(BiTree T)
{
    cout << T->data;
    return true;
}

bool createBiTree(BiTree &T)
{
    int num;
    cout << "请输入下一个二叉树节点数据" << endl;
    cin >> num;
    if (num == 0)
    {
        T = NULL;
    }
    else
    {
        T = new BiNode;
        T->data = num;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
    return true;
}

bool BinaryTreeLevelOrder(BiTree T)
{
    if (T == NULL)
    {
        cout << "Bitree is empty" << endl;
        return false;
    }
    queue<BiTree> q;
    q.push(T); //根节点入队
    while (!q.empty())
    {
        BiNode *v = q.front(); //保存出队节点到v
        q.pop(); //节点出队
        visit(v);
        if (v->lchild != NULL)
        {
            q.push(v->lchild);
        }
        if (v->rchild != NULL)
        {
            q.push(v->rchild);
        }
    }
    cout << endl;
    return true;
}

bool BinaryTreeFrontOrder(BiTree T)
{
    if (T == NULL)
    {
        return true;
    }
    visit(T);
    BinaryTreeFrontOrder(T->lchild);
    BinaryTreeFrontOrder(T->rchild);
    return true;
}

bool BinaryTreeBackOrder(BiTree T)
{
    if (T == NULL)
    {
        return true;
    }
    BinaryTreeBackOrder(T->lchild);
    BinaryTreeBackOrder(T->rchild);
    visit(T);
    return true;
}

bool BinaryTreeMiddleOrder(BiTree T)
{
    if (T == NULL)
    {
        return true;
    }
    BinaryTreeBackOrder(T->lchild);
    visit(T);
    BinaryTreeBackOrder(T->rchild);
    return true;
}
