#ifndef HASH_H
#define HASH_H
#define SIZE 23
#include <string>
#include <cmath>

using namespace std;

struct Node
{
    int key;
    string name;
    Node(int k, string str) {key = k; name = str;}
    Node() {key = 0; name = "";}
};

class hashTab
{
protected:
    int hashFunc1(int);
    int hashFunc2(int);
    bool check();
public:
    hashTab();
    Node** hashTable = new Node*[SIZE];
    void add(Node*);
    Node* remove(int);
    Node* search(int);
    bool *used = new bool[SIZE];

};

#endif // HASH_H
