#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    unsigned char barrel[125000];
} MyHashSet;

/** Initialize your data structure here. */
MyHashSet *myHashSetCreate()
{
    MyHashSet *myHashSet = (MyHashSet *)malloc(sizeof(MyHashSet));
    memset(myHashSet->barrel, 0, sizeof(myHashSet->barrel));
    return myHashSet;
}

void myHashSetAdd(MyHashSet *obj, int key)
{
    obj->barrel[key >> 3] |= 1 << (key % 8);
}

void myHashSetRemove(MyHashSet *obj, int key)
{
    obj->barrel[key >> 3] &= ~(1 << (key % 8));
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet *obj, int key)
{
    return obj->barrel[key >> 3] & (1 << (key % 8));
}

void myHashSetFree(MyHashSet *obj)
{
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
