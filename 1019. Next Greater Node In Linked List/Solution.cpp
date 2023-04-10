#include <stack>
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
    vector<int> nextLargerNodes(ListNode* head)
    {
        vector<int> res;
        stack<int> stk;
        while (head) {
            while (!stk.empty() && head->val > res[stk.top()]) {
                res[stk.top()] = head->val;
                stk.pop();
            }
            stk.emplace(res.size());
            res.emplace_back(head->val);
            head = head->next;
        }
        while (!stk.empty()) {
            res[stk.top()] = 0;
            stk.pop();
        }
        return res;
    }
};
