#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return true;
    }
    return false;
}
