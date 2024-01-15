/**
 * Definition for singly-linked list.
 **/
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode dummy(0, head);
        for (ListNode* p = &dummy; p->next && p->next->next;) {
            if (p->next->val == p->next->next->val) {
                int val = p->next->val;
                ListNode* q = p->next->next->next;
                while (q && q->val == val)
                    q = q->next;
                p->next = q;
            } else
                p = p->next;
        }
        return dummy.next;
    }
};
