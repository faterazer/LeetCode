#include <algorithm>
#include <functional>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k)
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
};
