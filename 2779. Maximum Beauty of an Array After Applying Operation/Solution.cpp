#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int maximumBeauty_MK1(vector<int>& nums, int k)
    {
        int max_val = ranges::max(nums);
        vector<int> buff(max_val + 2, 0);
        for (const int& x : nums) {
            buff[max(0, x - k)]++;
            buff[min(max_val, x + k) + 1]--;
        }

        int res = 0, s = 0;
        for (int x : buff) {
            s += x;
            res = max(res, s);
        }
        return res;
    }

    // 时间复杂度：O(nlgn)
    // 空间复杂度：O(1)
    int maximumBeauty_MK2(vector<int>& nums, int k)
    {
        ranges::sort(nums);
        int res = 1, left = 0, n = nums.size();
        for (int right = 1; right < n; right++) {
            while (nums[right] - nums[left] > k * 2)
                left++;
            res = max(res, right - left + 1);
        }
        return res;
    }
};
