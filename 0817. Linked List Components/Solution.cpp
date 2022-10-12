#include <unordered_set>
#include <vector>
using namespace std;

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
    int numComponents(ListNode* head, vector<int>& nums)
    {
        unordered_set<int> subset(nums.begin(), nums.end());
        int res = 0, is_component = 0;
        while (head) {
            if (subset.count(head->val)) {
                is_component = 1;
            } else {
                res += is_component;
                is_component = 0;
            }
            head = head->next;
        }
        return res + is_component;
    }
};
