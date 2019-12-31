struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution
{
public:
    ListNode *getIntersectionNode_MK1(ListNode *headA, ListNode *headB);    // My solution
    ListNode *getIntersectionNode_MK2(ListNode *headA, ListNode *headB);    // Solution.md: Approach 3
private:
    int len(ListNode *head);
};

int Solution::len(ListNode *head)
{
    int l = 0;
    while (head) {
        l++;
        head = head->next;
    }
    return l;
}

// My solution.
// Time complexity: O(n)
// Space complexity: O(1)
ListNode* Solution::getIntersectionNode_MK1(ListNode *headA, ListNode *headB)
{
    int alen = len(headA), blen = len(headB);
    int diff = alen - blen;
    ListNode *h1 = headA, *h2 = headB;
    for (; diff > 0; diff--)
        h1 = h1->next;
    for (; diff < 0; diff++)
        h2 = h2->next;
    while (h1) {
        if (h1 == h2)
            return h1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return nullptr;
}

// Solution.md: Approach 3
ListNode* Solution::getIntersectionNode_MK2(ListNode *headA, ListNode *headB)
{
    ListNode *h1 = headA, *h2 = headB;
    while (h1 != h2) {
        h1 = h1 == nullptr ? headB : h1->next;
        h2 = h2 == nullptr ? headA : h2->next;
    }
    return h1;
}
