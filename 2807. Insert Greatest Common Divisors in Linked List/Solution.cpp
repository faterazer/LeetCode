#include <numeric>
using namespace std;

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
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        for (ListNode* p = head; p->next; p = p->next->next)
            p->next = new ListNode(gcd(p->val, p->next->val), p->next);
        return head;
    }
};
