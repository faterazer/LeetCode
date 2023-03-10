#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p)
    {
        int total_sum = 0;
        for (const int& e : nums)
            total_sum = (total_sum + e) % p;
        if (total_sum == 0)
            return 0;

        int n = nums.size(), res = n, pre_sum = 0;
        unordered_map<int, int> memo { { pre_sum, -1 } };
        for (int i = 0; i < n; i++) {
            pre_sum = (pre_sum + nums[i]) % p;
            memo[pre_sum] = i;
            auto it = memo.find((pre_sum - total_sum + p) % p);
            if (it != memo.end())
                res = min(res, i - it->second);
        }
        return res < n ? res : -1;
    }
};
