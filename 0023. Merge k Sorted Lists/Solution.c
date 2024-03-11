#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *dummy = malloc(sizeof(struct ListNode)), *p = dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return dummy->next;
}

struct ListNode* mergeLists(struct ListNode** lists, int lo, int hi)
{
    if (lo > hi)
        return NULL;
    if (lo == hi)
        return lists[lo];

    int m = lo + (hi - lo) / 2;
    struct ListNode* left = mergeLists(lists, lo, m);
    struct ListNode* right = mergeLists(lists, m + 1, hi);
    return merge(left, right);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    return mergeLists(lists, 0, listsSize - 1);
}
