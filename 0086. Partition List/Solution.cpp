struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *p = dummy_head, *last = dummy_head;
        while (p && p->next) {
            if (p->next->val >= x)
                p = p->next;
            else if (p == last) {
                last = last->next;
                p = p->next;
            }
            else {
                ListNode *t = p->next;
                p->next = p->next->next;
                t->next = last->next;
                last->next = t;
                last = last->next;
            }
        }
        return dummy_head->next;
    }
};
