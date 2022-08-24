#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode)), *p = head;
    int carry = 0;
    while (l1 || l2 || carry) {
        int a = 0, b = 0;
        if (l1) {
            a = l1->val;
            l1 = l1->next;
        }
        if (l2) {
            b = l2->val;
            l2 = l2->next;
        }
        int sum = a + b + carry;
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = sum % 10;
        p->next = NULL;
        carry = sum / 10;
    }
    return head->next;
}
