#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(n);
        for (const vector<int>& edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }

        vector<int> visited(n, 0);
        function<int(int)> dfs = [&](int x) -> int {
            if (visited[x])
                return 0;
            visited[x] = 1;
            int res = 1;
            for (int neighour : graph[x])
                if (!visited[neighour])
                    res += dfs(neighour);
            return res;
        };

        long long res = 0, counted = 0;
        for (int i = 0; i < n; i++) {
            int cnt = dfs(i);
            res += 1LL * cnt * counted;
            counted += cnt;
        }
        return res;
    }
};
