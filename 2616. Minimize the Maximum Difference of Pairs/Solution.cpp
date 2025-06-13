#include <algorithm>
#include <functional>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p)
    {
        ranges::sort(nums);
        function<bool(int)> check = [&](int x) -> bool {
            int cnt = 0;
            for (size_t i = 1; i < nums.size() && cnt < p; ++i) {
                if (nums[i] - nums[i - 1] <= x) {
                    ++cnt;
                    ++i;
                }
            }
            return cnt >= p;
        };

        int lo = 0, hi = nums.back() - nums.front();
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (check(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
