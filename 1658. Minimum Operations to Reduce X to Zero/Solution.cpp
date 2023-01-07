#include <climits>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0), res = INT_MAX;
        int n = nums.size(), left = 0, right = 0, window_sum = 0;
        for (; right < n; right++) {
            window_sum += nums[right];
            while (left <= right && sum - window_sum < x)
                window_sum -= nums[left++];
            if (sum - window_sum == x)
                res = min(res, n - right + left - 1);
        }
        return res == INT_MAX ? -1 : res;
    }
};
