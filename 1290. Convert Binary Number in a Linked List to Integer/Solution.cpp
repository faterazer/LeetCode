struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int ret = 0;
        for (; head; head = head->next)
            ret = ret << 1 | head->val;
        return ret;
    }
};
