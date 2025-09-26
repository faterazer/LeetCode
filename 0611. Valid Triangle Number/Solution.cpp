#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int triangleNumber_MK1(vector<int>& nums)
    {
        ranges::sort(nums);
        int ans = 0;
        for (int k = nums.size() - 1; k >= 2; --k) {
            if (nums[0] + nums[1] > nums[k]) {
                ans += (k + 1) * k * (k - 1) / 6;
                break;
            }
            if (nums[k - 2] + nums[k - 1] <= nums[k])
                continue;

            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    ans += j - i;
                    --j;
                } else
                    ++i;
            }
        }
        return ans;
    }

    int triangleNumber_MK2(vector<int>& nums)
    {
        ranges::sort(nums);
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] == 0)
                continue;
            
            int j = i + 1;
            for (int k = i + 2; k < n; ++k) {
                while (nums[k] - nums[j] >= nums[i])
                    ++j;
                ans += k - j;
            }
        }
        return ans;
    }
};
