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
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        unordered_set<int> ust(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
            if (ust.contains(cur->val))
                prev->next = cur->next;
            else
                prev = cur;
        }
        return dummy->next;
    }
};
