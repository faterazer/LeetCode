#include <algorithm>
#include <functional>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minCapability_MK1(vector<int>& nums, int k) // 二分 + DP
    {
        function<bool(int)> check = [&](int mx) -> bool {
            int f0 = 0, f1 = 0;
            for (int x : nums) {
                if (x > mx)
                    f0 = f1;
                else {
                    int tmp = f1;
                    f1 = max(f1, f0 + 1);
                    f0 = tmp;
                }
            }
            return f1 >= k;
        };

        auto p = ranges::minmax(nums);
        int left = p.min, right = p.max;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    int minCapability_MK2(vector<int>& nums, int k) // 二分 + 贪心
    {
        function<bool(int)> check = [&](int mx) -> bool {
            int cnt = 0;
            for (size_t i = 0; i < nums.size(); ++i) {
                if (nums[i] <= mx) {
                    ++cnt;
                    ++i;
                }
            }
            return cnt >= k;
        };

        auto p = ranges::minmax(nums);
        int left = p.min, right = p.max;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
