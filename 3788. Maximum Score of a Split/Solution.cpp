#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums)
    {
        long long pre_sum = reduce(nums.begin(), nums.end() - 1, 0LL), result = numeric_limits<long long>::min();
        int suf_min = nums.back(), n = nums.size();
        for (int i = n - 2; i >= 0; --i) {
            result = max(result, pre_sum - suf_min);
            pre_sum -= nums[i];
            suf_min = min(suf_min, nums[i]);
        }
        return result;
    }
};
