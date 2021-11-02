#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void deleteNode(struct ListNode* node)
{
    node->val = node->next->val;
    struct ListNode *tp = node->next;
    node->next = tp->next;
    free(tp);
}
