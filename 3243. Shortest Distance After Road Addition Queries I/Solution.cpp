#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
    {
        vector<vector<int>> shortcuts(n);
        vector<int> f(n);
        iota(f.begin(), f.end(), 0);

        vector<int> ans;
        ans.reserve(queries.size());
        for (const vector<int>& query : queries) {
            int u = query[0], v = query[1];
            shortcuts[u].emplace_back(v);
            if (f[v] > f[u] + 1) {
                f[v] = f[u] + 1;
                for (int i = v; i < n; ++i) {
                    f[i] = min(f[i], f[i - 1] + 1);
                    for (int j : shortcuts[i])
                        f[j] = min(f[j], f[i] + 1);
                }
            }
            ans.emplace_back(f[n - 1]);
        }
        return ans;
    }
};
