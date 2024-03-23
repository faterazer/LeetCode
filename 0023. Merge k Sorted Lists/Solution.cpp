#include <queue>
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
    ListNode* mergeKLists_MK1(vector<ListNode*>& lists) // 分治法
    {
        return mergeKLists(lists, 0, lists.size() - 1);
    }

    ListNode* mergeKLists_MK2(vector<ListNode*>& lists) // 堆
    {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> min_heap(cmp);
        for (ListNode* p : lists)
            if (p)
                min_heap.emplace(p);

        ListNode *dummy = new ListNode, *cur = dummy;
        while (!min_heap.empty()) {
            ListNode* p = min_heap.top();
            min_heap.pop();
            cur->next = p;
            cur = cur->next;
            if (p->next)
                min_heap.emplace(p->next);
        }
        return dummy->next;
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
