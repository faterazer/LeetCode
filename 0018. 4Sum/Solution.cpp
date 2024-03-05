#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        ranges::sort(nums);
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            long long sum = 0LL + nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (sum > target)
                break;

            sum = 0LL + nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1];
            if (sum < target)
                continue;

            threeSum(nums, i + 1, target - nums[i], res);
        }
        return res;
    }

private:
    void threeSum(vector<int>& nums, int start_idx, int target, vector<vector<int>>& res)
    {
        int n = nums.size();
        for (int i = start_idx; i < n - 2; i++) {
            if (i > start_idx && nums[i] == nums[i - 1])
                continue;

            long long sum = 0LL + nums[i] + nums[i + 1] + nums[i + 2];
            if (sum > target)
                break;

            sum = 0LL + nums[i] + nums[n - 2] + nums[n - 1];
            if (sum < target)
                continue;

            int j = i + 1, k = n - 1;
            while (j < k) {
                sum = 0LL + nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    res.push_back({ nums[start_idx - 1], nums[i], nums[j++], nums[k--] });
                    for (; j < k && nums[j] == nums[j - 1]; j++)
                        ;
                    for (; j < k && nums[k] == nums[k + 1]; k--)
                        ;
                } else if (sum < target)
                    j++;
                else
                    k--;
            }
        }
    }
};
