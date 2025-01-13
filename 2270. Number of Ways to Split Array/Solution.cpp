#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums)
    {
        int ans = 0;
        long long pre_sum = 0, total = reduce(nums.begin(), nums.end(), 0LL);
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            pre_sum += nums[i];
            if (pre_sum >= total - pre_sum)
                ++ans;
        }
        return ans;
    }
};
