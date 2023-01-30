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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
    {
        ListNode* p = list1;
        for (int i = 0; i < a - 1; i++)
            p = p->next;
        ListNode* q = p;
        for (int i = a - 1; i <= b; i++)
            q = q->next;
        p->next = list2;
        while (p->next)
            p = p->next;
        p->next = q;
        return list1;
    }
};
