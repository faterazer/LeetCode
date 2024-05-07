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
    ListNode* doubleIt(ListNode* head)
    {
        if (head->val > 4)
            head = new ListNode(0, head);

        for (ListNode* p = head; p; p = p->next) {
            p->val = p->val * 2 % 10;
            if (p->next && p->next->val > 4)
                p->val++;
        }
        return head;
    }
};
