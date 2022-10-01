#include <cstring>
#include <functional>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Time complexity: O(n)
     * Space complexity: O(n)
     */
    int rotatedDigits_MK1(int N)
    {
        // dp[i] = 0, invalid number
        // dp[i] = 1, valid and same number
        // dp[i] = 2, valid and different number

        int cnt = 0;
        vector<int> dp(N + 1, 0);
        for (size_t i = 0; i < dp.size(); i++) {
            if (i == 0 || i == 1 || i == 8)
                dp[i] = 1;
            else if (i == 2 || i == 5 || i == 6 || i == 9) {
                dp[i] = 2;
                cnt++;
            } else {
                int a = dp[i % 10], b = dp[i / 10];
                if (a == 1 && b == 1)
                    dp[i] = 1;
                else if (a >= 1 && b >= 1) {
                    dp[i] = 2;
                    cnt++;
                }
            }
        }
        return cnt;
    }

    /**
     * Time complexity: O(lgn)
     * Space complexity: O(lgn)
     */
    int rotatedDigits_MK2(int n)
    {
        string s = to_string(n);
        int sn = s.size(), dp[sn][2];
        memset(dp, -1, sizeof(dp));

        function<int(int, bool, bool)> dfs = [&](int i, bool is_limit, bool has_diff) -> int {
            if (i == sn)
                return has_diff;
            if (!is_limit && dp[i][has_diff] >= 0)
                return dp[i][has_diff];

            int res = 0;
            int lim = is_limit ? s[i] - '0' : 9;
            for (int d = 0; d <= lim; ++d)
                if (check[d] != -1)
                    res += dfs(i + 1, is_limit && d == lim, has_diff | check[d]);
            if (!is_limit)
                dp[i][has_diff] = res;
            return res;
        };

        return dfs(0, true, false);
    }

private:
    // 0: invalid number. 1: valid and same number. 2: valid and different number.
    static constexpr int check[10] = { 0, 0, 1, -1, -1, 1, 1, -1, 0, 1 };
};
