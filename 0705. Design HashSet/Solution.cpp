#include <bitset>
using namespace std;

class MyHashSet
{
public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
    }

    void add(int key)
    {
        barrel[key] = 1;
    }

    void remove(int key)
    {
        barrel[key] = 0;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return barrel[key];
    }

private:
    bitset<100001> barrel;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
