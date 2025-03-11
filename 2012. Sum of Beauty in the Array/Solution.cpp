#include <vector>
using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> suf_min(n, INT_MAX);
        suf_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 1; --i)
            suf_min[i] = min(suf_min[i + 1], nums[i]);

        int ans = 0, pre_max = nums[0];
        for (int i = 1; i < n - 1; ++i) {
            if (pre_max < nums[i] && nums[i] < suf_min[i + 1])
                ans += 2;
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                ans += 1;
            pre_max = max(pre_max, nums[i]);
        }
        return ans;
    }
};
