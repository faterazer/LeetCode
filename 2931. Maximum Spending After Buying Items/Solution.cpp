#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values)
    {
        int m = values.size(), n = values[0].size();

        auto comp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return values[a.first][a.second] > values[b.first][b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (int i = 0; i < m; ++i)
            pq.emplace(i, n - 1);

        long long ans = 0;
        for (int d = 1; d <= m * n; ++d) {
            auto [r, c] = pq.top();
            pq.pop();
            ans += 1LL * values[r][c] * d;
            if (c > 0)
                pq.emplace(r, c - 1);
        }
        return ans;
    }
};
