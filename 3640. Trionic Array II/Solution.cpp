#include <vector>
using namespace std;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums)
    {
        constexpr long long NEG_INF = LLONG_MIN / 2; // 除 2 防止下面加法（和负数相加）溢出
        long long ans = NEG_INF, f1 = NEG_INF, f2 = NEG_INF, f3 = NEG_INF;
        for (size_t i = 1; i < nums.size(); ++i) {
            long long x = nums[i - 1], y = nums[i];
            f3 = x < y ? max(f3, f2) + y : NEG_INF;
            f2 = x > y ? max(f2, f1) + y : NEG_INF;
            f1 = x < y ? max(f1, x) + y : NEG_INF;
            ans = max(ans, f3);
        }
        return ans;
    }
};
