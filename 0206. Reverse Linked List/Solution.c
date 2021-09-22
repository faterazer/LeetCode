#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Iterative
struct ListNode* reverseList_MK1(struct ListNode* head)
{
    struct ListNode *new_head = (struct ListNode*)malloc(sizeof(struct ListNode)), *tp = NULL;
    new_head->next = NULL;
    while (head) {
        tp = head;
        head = head->next;
        tp->next = new_head->next;
        new_head->next = tp;
    }
    head = new_head->next;
    free(new_head);
    new_head->next = NULL;
    return head;
}

// Recursive
struct ListNode* reverseList_MK2(struct ListNode* head)
{
    if (head && head->next) {
        struct ListNode* tmp_head = reverseList_MK2(head->next);
        head->next->next = head;
        head->next = NULL;
        return tmp_head;
    } else {
        return head;
    }
}
