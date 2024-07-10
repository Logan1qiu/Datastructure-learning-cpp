#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <queue>
using namespace std;

typedef struct BiNode
{
    int data;
    BiNode *lchild, *rchild;
}BiNode, *BiTree;

bool isBiTreeEmpty(BiTree T);
bool visit(BiTree T);//访问节点数据
bool createBiTree(BiTree &T);//先序遍历递归构造二叉树
bool BinaryTreeLevelOrder(BiTree T);//层次遍历
bool BinaryTreeFrontOrder(BiTree T);//先序遍历
bool BinaryTreeBackOrder(BiTree T);//后序遍历
bool BinaryTreeMiddleOrder(BiTree T);//中序遍历
