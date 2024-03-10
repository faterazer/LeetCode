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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode *dummy = new ListNode(), *tail = dummy, *p = head;
        while (p) {
            int i = 0;
            while (p && i++ < k)
                p = p->next;
            if (i < k)
                break;

            ListNode* new_tail = head;
            while (head != p) {
                ListNode* t = head;
                head = head->next;
                t->next = tail->next;
                tail->next = t;
            }
            tail = new_tail;
        }
        tail->next = head;
        return dummy->next;
    }
};
