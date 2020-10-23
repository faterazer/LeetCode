#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head, *tp = NULL;
    struct ListNode *half = (struct ListNode*)malloc(sizeof(struct ListNode));
    half->next = NULL;
    while (fast && fast->next) {
        fast = fast->next->next;
        tp = slow;
        slow = slow->next;
        tp->next = half->next;
        half->next = tp;
    }
    half = half->next;
    if (fast)
        slow = slow->next;
    for (; slow; half = half->next, slow = slow->next)
        if (half->val != slow->val)
            return false;
    return true;
}
