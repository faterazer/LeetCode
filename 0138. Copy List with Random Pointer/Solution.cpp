#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if (!head)
            return nullptr;
        for (Node *p = head; p; p = p->next->next) {
            Node *tp = new Node(p->val);
            tp->next = p->next;
            p->next = tp;
        }
        for (Node *p = head; p; p = p->next->next)
            p->next->random = p->random ? p->random->next : nullptr;
        Node *r = head->next;
        for (Node *p = head; p; p = p->next) {
            Node *q = p->next;
            p->next = p->next->next;
            q->next = q->next ? q->next->next : nullptr;
        }
        return r;
    }
};
