#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> ans(1 << n);
        for (int i = 0; i < (1 << n); ++i)
            for (int j = 0; j < n; ++j)
                if (i >> j & 1)
                    ans[i].emplace_back(nums[j]);
        return ans;
    }
};
