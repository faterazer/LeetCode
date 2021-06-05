#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode *head, int val)
{
    if (!head)
        return head;
    struct ListNode *next = removeElements(head->next, val);
    if (head->val == val) {
        free(head);
        return next;
    } else {
        head->next = next;
        return head;
    }
}
