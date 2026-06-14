#include <vector>
using namespace std;

//  Definition for singly-linked list.
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
    int pairSum(ListNode* head)
    {
        int n = 0;
        for (ListNode* p = head; p; p = p->next)
            ++n;

        int m = n / 2;
        vector<int> buffer(m);
        ListNode* p = head;
        for (int i = 0; i < m; ++i) {
            buffer[i] = p->val;
            p = p->next;
        }
        
        int result = 0;
        for (int i = m; i < n; ++i) {
            result = max(result, buffer[n - 1 - i] + p->val);
            p = p->next;
        }
        return result;
    }
};
