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
    void reorderList(ListNode* head)
    {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* dummy = new ListNode();
        fast = slow->next;
        slow->next = nullptr;
        while (fast) {
            ListNode* t = fast;
            fast = fast->next;
            t->next = dummy->next;
            dummy->next = t;
        }

        ListNode *p1 = head, *p2 = dummy->next;
        dummy->next = nullptr;
        ListNode* cur = dummy;
        while (p1 && p2) {
            cur->next = p1;
            p1 = p1->next;
            cur->next->next = p2;
            p2 = p2->next;
            cur = cur->next->next;
        }
        cur->next = p1 ? p1 : p2;
        delete dummy;
    }
};
