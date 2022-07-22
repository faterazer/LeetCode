#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode* h1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* h2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p1 = h1, *p2 = h2;
    while (head) {
        if (head->val < x)
            p1 = p1->next = head;
        else
            p2 = p2->next = head;
        head = head->next;
    }
    p2->next = NULL;
    p1->next = h2->next;
    return h1->next;
}
