#ifndef TREE_H
#define TREE_H

#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Node
{
public:
  int key;
  string name;
  unsigned char height;
  Node* left;
  Node* right;
  Node();
  Node(int k, string str) {key = k; name = str; left = right = nullptr; height = 1;}
};

class Tree
{
    unsigned char height(Node*);
    void fixHeight(Node*);
    int bFactor(Node*);
    Node* rotateLeft(Node* );
    Node* rotateRight(Node*);
    Node* findMin(Node*);
    Node* removeMin(Node*);
public:
    Tree(); 
    Node* add(Node*,int, string);
    Node* remove(Node*, int);
    Node* find(Node*, int);
    vector<Node> PreOrderTree(Node*);
    vector<Node> PostOrderTree(Node*);
    vector<Node> SymmetricOrderTree(Node*);
    Node* balance(Node*);
    vector<Node> vect;
    Node *tmp;
};

#endif // TREE_H
