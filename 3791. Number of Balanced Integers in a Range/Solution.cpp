#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    long long countBalanced(long long low, long long high)
    {
        if (high < 11)
            return 0;
        low = max(low, 11LL);

        string low_s = to_string(low), high_s = to_string(high);
        low_s = string(high_s.size() - low_s.size(), '0') + low_s;

        int n = high_s.size(), target = n * 9 / 2;;
        vector<vector<long long>> memo(n, vector<long long>(n * 9 + 1, -1));
        auto dfs = [&](this auto&& self, int i, int diff, bool limit_low, bool limit_high) -> long long {
            if (i == n)
                return diff == target;;
            if (abs(target - diff) > (n - i + 1) / 2 * 9)
                return 0;
            if (!limit_low && !limit_high && memo[i][diff] != -1)
                return memo[i][diff];

            int lo = limit_low ? low_s[i] - '0' : 0;
            int hi = limit_high ? high_s[i] - '0' : 9;
            int sign = i % 2 == 0 ? 1 : -1;
            long long result = 0;
            for (int d = lo; d <= hi; ++d)
                result += self(i + 1, diff + sign * d, limit_low && d == lo, limit_high && d == hi);
            if (!limit_low && !limit_high)
                memo[i][diff] = result;
            return result;
        };

        return dfs(0, n * 9 / 2, true, true);
    }
};
