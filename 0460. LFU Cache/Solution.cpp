#include <list>
#include <unordered_map>
using namespace std;

struct Node {
    int key, val, freq;
    Node(int _key, int _val, int _freq)
        : key(_key)
        , val(_val)
        , freq(_freq)
    {
    }
};

class LFUCache {
public:
    LFUCache(int _capacity)
        : capacity(_capacity)
    {
    }

    int get(int key)
    {
        auto it = key2node.find(key);
        if (it == key2node.end())
            return -1;
        list<Node>::iterator node = it->second;
        int val = node->val, freq = node->freq;
        freq2list_del_node(node);
        freq2list[freq + 1].emplace_front(key, val, freq + 1);
        key2node[key] = freq2list[freq + 1].begin();
        return val;
    }

    void put(int key, int value)
    {
        auto it = key2node.find(key);
        if (it == key2node.end()) {
            if (key2node.size() == capacity) {
                Node node = freq2list[min_freq].back();
                freq2list[min_freq].pop_back();
                key2node.erase(node.key);
                if (freq2list[min_freq].empty())
                    freq2list.erase(min_freq);
            }
            freq2list[1].emplace_front(key, value, 1);
            key2node[key] = freq2list[1].begin();
            min_freq = 1;
        } else {
            list<Node>::iterator node = it->second;
            int freq = node->freq;
            freq2list_del_node(node);
            freq2list[freq + 1].emplace_front(key, value, freq + 1);
            key2node[key] = freq2list[freq + 1].begin();
        }
    }

private:
    void freq2list_del_node(list<Node>::iterator it)
    {
        int freq = it->freq;
        freq2list[freq].erase(it);
        if (freq2list[freq].empty()) {
            freq2list.erase(freq);
            if (min_freq == freq)
                ++min_freq;
        }
    }

    int min_freq = 0, capacity;
    unordered_map<int, list<Node>::iterator> key2node;
    unordered_map<int, list<Node>> freq2list;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
