#include <algorithm>
#include <bit>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m)
    {
        ranges::nth_element(nums, nums.end() - m);
        int n = nums.size();
        bool same = true;
        for (int i = n - m; i < n - 1; ++i) {
            if (nums[i] != nums.back()) {
                same = false;
                break;
            }
        }
        if (same)
            return nums.back() + k / m;
        
        int max_width = bit_width(static_cast<unsigned>(ranges::max(nums)) + k / m);
        vector<int> ops(n);
        int result = 0;
        for (int bit = max_width - 1; bit >= 0; --bit) {
            int target = result | (1 << bit);
            for (int i = 0; i < n; ++i) {
                int x = nums[i];
                int b = bit_width(static_cast<unsigned>(target & ~x));
                int mask = b < 31 ? (1 << b) - 1 : numeric_limits<int>::max();
                ops[i] = (target & mask) - (x & mask);
            }
            ranges::nth_element(ops, ops.begin() + m);
            if (reduce(ops.begin(), ops.begin() + m, 0LL) <= k)
                result = target;
        }
        return result;
    }
};
