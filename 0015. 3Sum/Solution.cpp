#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        ranges::sort(nums);
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
                break;
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0)
                continue;

            int j = i + 1, k = n - 1, target = -nums[i];
            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    res.push_back({ nums[i], nums[j++], nums[k--] });
                    for (; j < k && nums[j] == nums[j - 1]; j++)
                        ;
                    for (; j < k && nums[k] == nums[k + 1]; k--)
                        ;
                } else if (nums[j] + nums[k] < target)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};
