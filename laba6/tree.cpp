#include "tree.h"

Tree::Tree()
{
}

unsigned char Tree::height(Node *p)
{
	return p?p->height:0;
}

void Tree::fixHeight(Node *p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr?hl:hr)+1;
}

int Tree::bFactor(Node *p)
{
	return height(p->right) - height(p->left);
}

Node* Tree::rotateLeft(Node *q)
{
    Node* p = q->right;
    if(!p)
        return q;

    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}

Node* Tree::rotateRight(Node *p)
{
    Node* q = p->left;
    if(!q)
        return p;

    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

Node* Tree::balance(Node *p)
{
    fixHeight(p);
    if(bFactor(p) == 2)
    {
        if(bFactor(p->right) < 0)
            p->right = rotateRight(p->right);

        return rotateLeft(p);
    }
    if(bFactor(p) == -2)
    {
        if(bFactor(p->left) > 0)
            p->left = rotateLeft(p->left);

        return rotateRight(p);
    }
    return p;
}

Node* Tree::add(Node *p, int k, string a)
{
    if(!p)
        return new Node(k, a);
    if(k < p->key)
        p->left = add(p->left, k, a);

    else
        p->right = add(p->right, k, a);

    return balance(p);
}

Node* Tree::findMin(Node *p)
{
    return p->left?findMin(p->left):p;
}

Node* Tree::removeMin(Node *p)
{
    if(p->left == 0)
        return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}

Node* Tree::remove(Node *p, int k)
{
    if(!p)
        return 0;
    if(k < p->key)
        p->left = remove(p->left, k);
    else if (k > p->key)
        p->right = remove(p->right, k);
    else
    {
        Node *l = p->left;
        Node *r = p->right;
        delete p;
        if(!r)
            return l;
        Node *min = findMin(r);
        min->right = removeMin(r);
        min->left = l;
        return balance(min);
    }
    return balance(p);
}

Node* Tree::find(Node *p, int k)
{
    if(!p) return 0;
    if(k == p->key)
    {
        return p;
    }
    if(k < p->key)
    {
        return find(p->left, k);
    }
    else return find(p->right, k);
}

vector<Node> Tree::PreOrderTree(Node *p)
{
    if(p)
    {
        tmp->key = p->key;
        tmp->name = p->name;
        vect.push_back(*tmp);
        PreOrderTree(p->left);
        PreOrderTree(p->right);
    }
    return vect;
}

vector<Node> Tree::PostOrderTree(Node *p)
{
    if(p)
    {
        PostOrderTree(p->left);
        PostOrderTree(p->right);
        tmp->key = p->key;
        tmp->name = p->name;
        vect.push_back(*tmp);
    }
    return vect;
}

vector<Node> Tree::SymmetricOrderTree(Node *p)
{
    if(p)
    {
        SymmetricOrderTree(p->left);
        tmp->key = p->key;
        tmp->name = p->name;
        vect.push_back(*tmp);
        SymmetricOrderTree(p->right);
    }
    return vect;
}

































