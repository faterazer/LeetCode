struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head);
};

ListNode* Solution::deleteDuplicates(ListNode *head)
{
    ListNode *p = head;
    while (p) {
        if (p->next && p->next->val == p->val) {
            ListNode *t = p->next;
            p->next = t->next;
            delete t;
        }
        else
            p = p->next;
    }
    return head;
}
