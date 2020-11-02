struct ListNode
{
    int val;
    struct ListNode *next;
};

int getDecimalValue(struct ListNode *head)
{
    int ret = 0;
    for (; head; head = head->next)
        ret = ret << 1 | head->val;
    return ret;
}
