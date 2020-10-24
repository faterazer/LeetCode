#include <vector>
using namespace std;

class MyHashMap
{
public:
    /** Initialize your data structure here. */
    MyHashMap() : buckets(769)
    {
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        vector<pair<int, int>> &bucket = buckets[key % buckets.size()];
        for (pair<int, int> &item : bucket) {
            if (item.first == key) {
                item.second = value;
                return;
            }
        }
        bucket.emplace_back(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        const vector<pair<int, int>> &bucket = buckets[key % buckets.size()];
        for (const pair<int, int> &item : bucket)
            if (item.first == key)
                return item.second;
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        vector<pair<int, int>> &bucket = buckets[key % buckets.size()];
        for (pair<int, int> &item : bucket) {
            if (item.first == key) {
                item = bucket.back();
                bucket.pop_back();
            }
        }
    }

private:
    vector<vector<pair<int, int>>> buckets;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
