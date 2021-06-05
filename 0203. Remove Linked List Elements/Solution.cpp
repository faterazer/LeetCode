struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val);
};

ListNode* Solution::removeElements(ListNode *head, int val)
{
    ListNode *new_head = new ListNode(0);
    new_head->next = head;
    ListNode *prev = new_head, *curr = head;
    while (curr) {
        if (curr->val == val) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    head = new_head->next;
    delete new_head;
    return head;
}
