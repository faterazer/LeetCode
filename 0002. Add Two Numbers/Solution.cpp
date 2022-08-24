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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *head = new ListNode(), *p = head;
        int carry = 0;
        while (l1 || l2 || carry) {
            int a = 0, b = 0;
            if (l1) {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                b = l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(a + b + carry);
            p = p->next;
            carry = p->val / 10;
            p->val = p->val % 10;
        }
        return head->next;
    }
};
