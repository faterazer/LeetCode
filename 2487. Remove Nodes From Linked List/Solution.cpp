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
    ListNode* removeNodes(ListNode* head)
    {
        head = reverse(head);
        for (ListNode* p = head; p->next;) {
            if (p->val > p->next->val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return reverse(head);
    }

private:
    ListNode* reverse(ListNode* head)
    {
        ListNode dummy;
        while (head) {
            ListNode* p = head;
            head = head->next;
            p->next = dummy.next;
            dummy.next = p;
        }
        return dummy.next;
    }
};
