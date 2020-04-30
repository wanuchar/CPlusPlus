#include "hash.h"

hashTab::hashTab()
{
    for(int i = 0; i < SIZE; i++)
    {
        hashTable[i] = NULL;
        used[i] = false;
    }
}

int hashTab::hashFunc1(int key)
{
    if(key < 0) return SIZE + key;
    return key % SIZE;
}

int hashTab::hashFunc2(int key)
{
    if(key < 0) return 1+ SIZE - 2 + key;
    else return 1+(key % (SIZE - 2));
}

void hashTab::add(Node* insrt)
{
    int ind = hashFunc1(insrt->key);
    int k = hashFunc2(insrt->key);
    int i = 0;
    while (used[ind] && (hashTable[ind] != insrt))
    {
        ind = (ind + i*k) % SIZE;
        i++;
        if(!check()) return;
    }
    if(!used[ind])
    {
        used[ind] = true;
        hashTable[ind] = insrt;
    }
}

Node* hashTab::search(int key)
{
    for(int i = 0; i < SIZE; i++)
    {
        if(hashTable[i])
        {
            if (hashTable[i]->key == key)
            {
                return hashTable[i];
            }
        }
    }
    return NULL;
}

Node* hashTab::remove(int key)
{
    int ind = hashFunc1(key);
    int ind1 = hashFunc2(key);
    int i = 0;
    if(!search(key)) {
        return NULL;
    }
    while(!hashTable[ind])
    {
        ind = (ind + i*ind1) % SIZE;
        i++;
    }
    while (hashTable[ind]->key != key)
    {
        ind = (ind + i*ind1) % SIZE;
        i++;
        while(!hashTable[ind])
        {
            ind = (ind + i*ind1) % SIZE;
            i++;
        }
    }
    if(hashTable[ind]->key == key)
    {
        hashTable[ind] = nullptr;
        used[ind] = false;
    }
    return hashTable[ind];
}

bool hashTab::check()
{
    for (int i = 0; i < SIZE; i++)
    {
        if(used[i] == true) return true;
    }
    return false;
}
