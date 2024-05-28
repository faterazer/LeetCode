#include <vector>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k)
    {
        vector<int> mono_stk;
        for (size_t i = 0; i < nums.size(); i++) {
            while (!mono_stk.empty() && nums[i] < mono_stk.back() && nums.size() - i + mono_stk.size() > k)
                mono_stk.pop_back();

            if (mono_stk.size() < k)
                mono_stk.emplace_back(nums[i]);
        }
        return mono_stk;
    }
};
