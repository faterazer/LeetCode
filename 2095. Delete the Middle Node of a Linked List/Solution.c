#include <stddef.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteMiddle(struct ListNode* head)
{
    if (!head || !head->next)
        return NULL;
    struct ListNode *pre = NULL, *slow = head, *fast = head;
    while (fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = slow->next;
    free(slow);
    return head;
}
