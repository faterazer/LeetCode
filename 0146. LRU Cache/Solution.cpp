#include <unordered_map>
using namespace std;

struct DLinkedNode {
    int key, val;
    DLinkedNode* pre = nullptr;
    DLinkedNode* next = nullptr;

    DLinkedNode() = default;

    DLinkedNode(int k, int v)
        : key(k)
        , val(v)
    {
    }
};

class LRUCache {
public:
    LRUCache(int _capacity)
        : capacity(_capacity)
    {
        head = new DLinkedNode;
        tail = new DLinkedNode;
        head->next = tail;
        tail->pre = head;
    }

    int get(int key)
    {
        auto it = table.find(key);
        if (it == table.end())
            return -1;
        DLinkedNode* p = it->second;
        detach(p);
        pushFront(p);
        return p->val;
    }

    void put(int key, int value)
    {
        if (table.count(key)) {
            DLinkedNode* p = table[key];
            p->val = value;
            detach(p);
            pushFront(p);
            return;
        }
        if (table.size() == capacity)
            popBack();
        DLinkedNode* p = new DLinkedNode(key, value);
        pushFront(p);
        table[key] = p;
    }

private:
    void detach(DLinkedNode* p)
    {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    void pushFront(DLinkedNode* p)
    {
        p->next = head->next;
        head->next = p;
        p->next->pre = p;
        p->pre = head;
    }

    void popBack()
    {
        DLinkedNode* p = tail->pre;
        p->pre->next = tail;
        tail->pre = p->pre;
        table.erase(p->key);
    }

    DLinkedNode *head = nullptr, *tail = nullptr;
    unordered_map<int, DLinkedNode*> table;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
