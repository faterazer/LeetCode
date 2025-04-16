#include <functional>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high)
    {
        string low_s = to_string(low), high_s = to_string(high);
        int n = high_s.size(), m = low_s.size();
        low_s = string(n - m, '0') + low_s;

        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n - m + 1, vector<int>(n / 2 * 9 + 1, -1)));
        function<int(int, int, bool, bool, int)> dfs = [&](int i, int start, bool limit_low, bool limit_high, int diff) -> int {
            if (diff < 0)
                return 0;
            if (i == n)
                return diff == 0;

            if (start != -1 && !limit_low && !limit_high && memo[i][start][diff] != -1)
                return memo[i][start][diff];

            int lo = limit_low ? low_s[i] - '0' : 0;
            int hi = limit_high ? high_s[i] - '0' : 9;
            if (start == -1 && (n - i) % 2)
                return lo ? 0 : dfs(i + 1, -1, true, false, 0);

            int ans = 0;
            bool is_left = start == -1 || i < (start + n) / 2;
            for (int d = lo; d <= hi; ++d)
                ans += dfs(
                    i + 1,
                    (start == -1 && d) ? i : start,
                    limit_low && d == lo,
                    limit_high && d == hi,
                    diff + (is_left ? d : -d));
            if (start != -1 && !limit_low && !limit_high)
                memo[i][start][diff] = ans;
            return ans;
        };

        return dfs(0, -1, true, true, 0);
    }
};
