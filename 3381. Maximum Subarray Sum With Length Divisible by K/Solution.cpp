#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k)
    {
        vector<long long> min_f(k, numeric_limits<long long>::max() / 2);
        min_f[0] = 0;
        long long prefix_sum = 0, result = numeric_limits<long long>::min();
        int n = nums.size();
        for (int j = 0; j < n; ++j) {
            prefix_sum += nums[j];
            int i = (j + 1) % k;
            result = max(result, prefix_sum - min_f[i]);
            min_f[i] = min(min_f[i], prefix_sum);
        }
        return result;
    }
};
