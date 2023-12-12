#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        stack<int> stk;
        vector<int> res(nums.size(), -1);
        for (size_t i = 0; i < nums.size() * 2 - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % nums.size()]) {
                res[stk.top()] = nums[i % nums.size()];
                stk.pop();
            }
            stk.emplace(i % nums.size());
        }
        return res;
    }
};
