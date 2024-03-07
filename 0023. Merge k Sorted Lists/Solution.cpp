#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        return mergeKLists(lists, 0, lists.size() - 1);
    }

private:
    ListNode* mergeKLists(vector<ListNode*>& lists, int lo, int hi)
    {
        if (lo > hi)
            return nullptr;
        if (lo == hi)
            return lists[lo];

        int m = lo + (hi - lo) / 2;
        ListNode* left = mergeKLists(lists, lo, m);
        ListNode* right = mergeKLists(lists, m + 1, hi);
        return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *dummy = new ListNode(), *p = dummy;
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
        p = dummy->next;
        delete dummy;
        return p;
    }
};
