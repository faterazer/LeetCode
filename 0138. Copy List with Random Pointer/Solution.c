#include <stddef.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* copyRandomList(struct Node* head)
{
    if (!head)
        return NULL;
    for (struct Node *p = head; p; p = p->next->next) {
        struct Node *tp = (struct Node *)malloc(sizeof(struct Node));
        tp->val = p->val;
        tp->next = p->next;
        p->next = tp;
    }
    for (struct Node *p = head; p; p = p->next->next) {
        struct Node *q = p->next;
        q->random = p->random ? p->random->next : NULL;
    }
    struct Node *r = head->next;
    for (struct Node *p = head; p; p = p->next) {
        struct Node *q = p->next;
        p->next = p->next->next;
        q->next = q->next ? q->next->next : NULL;
    }
    return r;
}
