#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        auto less_eq = [&](int i, int j) -> bool {
            for (const string& s : strs)
                if (s[i] > s[j])
                    return false;
            return true;
        };

        int m = strs[0].size();
        vector<int> dp(m, 1);
        for (int j = 1; j < m; ++j)
            for (int i = 0; i < j; ++i)
                if (dp[i] >= dp[j] && less_eq(i, j))
                    dp[j] = dp[i] + 1;
        return m - ranges::max(dp);
    }
};
