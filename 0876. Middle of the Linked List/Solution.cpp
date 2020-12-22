struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head);
};

ListNode* Solution::middleNode(ListNode *head)
{
    ListNode *p = head, *q = head;
    while (q && q->next) {
        p = p->next;
        q = q->next->next;
    }
    return p;
}
