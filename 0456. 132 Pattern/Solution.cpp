#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool find132pattern_MK1(vector<int>& nums)
    {
        stack<int> stk;
        int max_k = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            while (!stk.empty() && nums[i] > stk.top()) {
                max_k = stk.top();
                stk.pop();
            }
            stk.emplace(nums[i]);
            if (nums[i] < max_k)
                return true;
        }
        return false;
    }

    bool find132pattern_MK2(vector<int>& nums)
    {
        stack<int> stk;
        vector<int> pre_min { INT_MAX };
        for (size_t i = 0; i < nums.size(); ++i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i])
                stk.pop();
            if (!stk.empty() && pre_min[stk.top()] < nums[i])
                return true;
            stk.emplace(i);
            pre_min.emplace_back(min(pre_min.back(), nums[i]));
        }
        return false;
    }
};
