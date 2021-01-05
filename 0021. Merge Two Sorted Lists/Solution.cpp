#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode *, ListNode *);
    ListNode* mergeTwoLists_recursive(ListNode *, ListNode *);
};

ListNode* Solution::mergeTwoLists(ListNode *l1, ListNode *l2)
{
    // 本题中的单链表没有头结点，但是为了操作方便，先创建一个头结点，最后删掉即可。
    // In this problem, singly-linked list has no head node. But for convenience, 
    // I create a head node, and delete it later.
    ListNode *head = new ListNode(0), *p = head;
    while (l1 && l2) {
        ListNode *tp = nullptr;
        if (l1->val <= l2->val) {
            tp = l1;
            l1 = l1->next;
        }
        else {
            tp = l2;
            l2 = l2->next;
        }
        tp->next = p->next;
        p->next = tp;
        p = tp;
    }
    ListNode *remain = l1 ? l1 : l2;
    p->next = remain;
    // 删除头结点
    // delete my head node
    p = head;
    head = head->next;
    delete p;
    return head;
}

// 递归版本(recursive version)
ListNode* Solution::mergeTwoLists_recursive(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    else if (!l2)
        return l1;
    else if (l1->val <= l2->val) {
        l1->next = mergeTwoLists_recursive(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists_recursive(l1, l2->next);
        return l2;
    }
}
