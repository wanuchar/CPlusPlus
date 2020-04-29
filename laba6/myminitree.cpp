#include "myminitree.h"

MyMiniTree::MyMiniTree()
{
}

Node* MyMiniTree::ex(Node *p, int k)
{
    if(!p)
        return 0;
    if(k < p->key)
        p->left = ex(p->left, k);
    else if (k > p->key)
        p->right = ex(p->right, k);
    else
    {

        deleteBranch(&p);
    }
    return p;
}

void MyMiniTree::deleteBranch(Node **p)
{
    if(*p)
    {
        deleteBranch(&(*p)->left);
        deleteBranch(&(*p)->right);
        delete (*p);
        *p = NULL;
    }
}








