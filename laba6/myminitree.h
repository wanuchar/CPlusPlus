#ifndef MYMINITREE_H
#define MYMINITREE_H

#include "tree.h"

class MyMiniTree: public Tree
{
public:
    MyMiniTree();
    Node* ex(Node*, int);
    void deleteBranch(Node**);
};

#endif // MYMINITREE_H
