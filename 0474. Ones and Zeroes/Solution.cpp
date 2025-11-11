#include <algorithm>
#include <ranges>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int sum0 = 0, sum1 = 0;
        for (const string& s : strs) {
            if (s.size() > m + n)
                continue;
            int count0 = ranges::count(s, '0'), count1 = s.size() - count0;
            sum0 = min(sum0 + count0, m);
            sum1 = min(sum1 + count1, n);
            for (int i = sum0; i >= count0; --i)
                for (int j = sum1; j >= count1; --j)
                        dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1);
        }
        return ranges::max(dp | views::join);
    }
};
