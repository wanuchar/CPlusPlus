#include "myhash.h"

MyHash::MyHash()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = NULL;
        used[i] = false;
    }
}

void MyHash::ex()
{
    for (int i = 0; i < SIZE; i++)
    {
        if(hashTable[i] && hashTable[i]->key < 0)
        {       
             hashTable[i] = remove(hashTable[i]->key);
        }
    }
}
