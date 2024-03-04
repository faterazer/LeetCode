#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        ranges::sort(nums);
        int min_diff = INT_MAX, n = nums.size(), res = 0;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int sum = nums[i] + nums[i + 1] + nums[i + 2];
            if (sum > target && sum - target < min_diff)
                return sum;

            sum = nums[i] + nums[n - 2] + nums[n - 1];
            if (sum < target) {
                if (target - sum < min_diff) {
                    min_diff = target - sum;
                    res = sum;
                }
                continue;
            }

            int j = i + 1, k = n - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return target;
                else if (sum < target) {
                    if (target - sum < min_diff) {
                        min_diff = target - sum;
                        res = sum;
                    }
                    j++;
                } else {
                    if (sum - target < min_diff) {
                        min_diff = sum - target;
                        res = sum;
                    }
                    k--;
                }
            }
        }
        return res;
    }
};
