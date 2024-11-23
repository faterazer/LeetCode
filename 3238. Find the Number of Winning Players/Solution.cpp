#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick)
    {
        int cnt[n][11];
        memset(cnt, 0, sizeof(cnt));
        for (const vector<int>& p : pick)
            ++cnt[p[0]][p[1]];

        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (ranges::max(cnt[i]) > i)
                ++ans;
        return ans;
    }
};
