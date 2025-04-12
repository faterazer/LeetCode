#include <functional>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high)
    {
        string low_s = to_string(low), high_s = to_string(high);
        int n = high_s.size(), m = n / 2, k = n - low_s.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(k + 1, vector<int>(m * 18 + 1, -1)));

        function<int(int, int, bool, bool, int)> dfs = [&](int i, int start, bool limit_low, bool limit_high, int diff) -> int {
            if (i == n)
                return diff == m * 9;

            if (start != -1 && !limit_low && !limit_high && memo[i][start][diff] != -1)
                return memo[i][start][diff];

            // 第 i 个数位可以枚举的范围
            int lo = limit_low && i >= k ? low_s[i - k] - '0' : 0;
            int hi = limit_high ? high_s[i] - '0' : 9;

            if (start == -1 && (n - i) % 2)
                return lo > 0 ? 0 : dfs(i + 1, start, true, false, diff);

            int ans = 0;
            bool is_left = start == -1 || i < (start + n) / 2;
            for (int d = lo; d <= hi; ++d)
                ans += dfs(i + 1, start < 0 && d > 0 ? i : start, limit_low && d == lo, limit_high && d == hi, diff + (is_left ? d : -d));
            if (start != -1 && !limit_low && !limit_high)
                memo[i][start][diff] = ans;
            return ans;
        };

        return dfs(0, -1, true, true, m * 9); // -9m <= diff <= 9m, 初始化 diff = m * 9，避免出现负数导致 memo 下标越界
    }
};
