struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2)
{
    struct ListNode* p = list1;
    for (int i = 0; i < a - 1; i++)
        p = p->next;
    struct ListNode* q = p;
    for (int i = a - 1; i <= b; i++)
        q = q->next;
    p->next = list2;
    while (p->next)
        p = p->next;
    p->next = q;
    return list1;
}
