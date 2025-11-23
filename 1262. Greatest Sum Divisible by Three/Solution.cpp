#include <algorithm>
#include <array>
#include <climits>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumDivThree_MK1(vector<int>& nums)
    {
        int result = reduce(nums.begin(), nums.end());
        int m = result % 3;
        if (m == 0)
            return result;
        int mn1 = INT_MAX / 2, mn2 = INT_MAX / 2, mn3 = INT_MAX / 2;
        for (int x : nums) {
            if (x % 3 == 0)
                continue;
            else if (x % 3 != m) {
                if (x < mn1) {
                    mn2 = mn1;
                    mn1 = x;
                } else if (x < mn2)
                    mn2 = x;
            } else
                mn3 = min(mn3, x);
        }
        return result - min(mn1 + mn2, mn3);
    }

    // 使用动态规划
    int maxSumDivThree_MK2(vector<int>& nums)
    {
        array<int, 3> f{0, INT_MIN, INT_MIN};
        for (int x : nums) {
            array<int, 3> next_f = f;
            for (int i = 0; i < 3; ++i)
                next_f[(i + x) % 3] = max(f[(i + x) % 3], f[i] + x);
            f = move(next_f);
        }
        return f[0];
    }
};
