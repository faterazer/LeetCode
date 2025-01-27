#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k)
    {
        long long n = nums.size(), left = 0, bottom = 0, right_or = 0, ans = INT_MAX;
        for (long long right = 0; right < n; ++right) {
            right_or |= nums[right];
            while (left <= right && (nums[left] | right_or) >= k) {
                ans = min(ans, right - left + 1);
                ++left;
                if (left > bottom) {
                    for (int k = right - 1; k >= left; --k)
                        nums[k] |= nums[k + 1];
                    bottom = right;
                    right_or = 0;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
