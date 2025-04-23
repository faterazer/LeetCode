#include <functional>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // 暴力
    int countLargestGroup_MK1(int n)
    {
        int res = 0, max = 0, tmp;
        unordered_map<int, int> counter;
        for (int i = 1; i <= n; i++) {
            tmp = sumOfDigits(i);
            counter[tmp]++;
            if (counter[tmp] == max)
                res++;
            else if (counter[tmp] > max) {
                max = counter[tmp];
                res = 1;
            }
        }
        return res;
    }

    // 数位 DP
    int countLargestGroup_MK2(int n)
    {
        string s = to_string(n);
        int m = s.size();

        vector<vector<int>> memo(m, vector<int>(m * 9 + 1, -1));
        function<int(int, int, bool)> dfs = [&](int i, int remain, bool limit_high) -> int {
            if (i == m)
                return remain == 0;

            if (!limit_high && memo[i][remain] != -1)
                return memo[i][remain];

            int lo = 0, hi = limit_high ? s[i] - '0' : 9;
            int ans = 0;
            for (int d = lo; d <= min(hi, remain); ++d)
                ans += dfs(i + 1, remain - d, limit_high && d == hi);
            if (!limit_high)
                memo[i][remain] = ans;
            return ans;
        };

        int mx = 0, ans = 0;
        for (int i = 1; i <= 9 * m; ++i) {
            int cnt = dfs(0, i, true);
            if (cnt > mx) {
                mx = cnt;
                ans = 1;
            } else if (cnt == mx) {
                ++ans;
            }
        }
        return ans;
    }

private:
    int sumOfDigits(int n)
    {
        int sum = 0;
        for (; n; n /= 10)
            sum += n % 10;
        return sum;
    }
};
