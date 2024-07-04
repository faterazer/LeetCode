/**
 * Definition for singly-linked list.
 */
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
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode* p = head;
        for (ListNode* q = head->next; q && (q->val || q->next); q = q->next) {
            if (q->val)
                p->val += q->val;
            else {
                p->next = q;
                p = p->next;
            }
        }
        p->next = nullptr;
        return head;
    }
};
