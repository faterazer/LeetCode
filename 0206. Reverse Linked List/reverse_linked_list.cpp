struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *reverseList_MK1(ListNode *head);  // Iterative
    ListNode *reverseList_MK2(ListNode *head);  // Recursive
};

// Iterative
ListNode* Solution::reverseList_MK1(ListNode *head)
{
    ListNode *new_head = new ListNode(0);
    while (head) {
        ListNode *t = head;
        head = head->next;
        t->next = new_head->next;
        new_head->next = t;
    }
    head = new_head->next;
    delete new_head;
    return head;
}

// Recursive
ListNode* Solution::reverseList_MK2(ListNode *head)
{
    if (head && head->next) {
        ListNode *new_head = reverseList_MK2(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
    else
        return head;
}
