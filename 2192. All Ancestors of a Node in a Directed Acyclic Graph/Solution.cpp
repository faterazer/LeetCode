#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(n);
        for (const vector<int>& edge : edges)
            graph[edge[0]].emplace_back(edge[1]);

        vector<vector<int>> res(n);
        vector<int> visited(n, -1);
        int beg;

        function<void(int)> dfs = [&](int node) -> void {
            visited[node] = beg;
            for (int child : graph[node]) {
                if (visited[child] != beg) {
                    res[child].emplace_back(beg);
                    dfs(child);
                }
            }
        };

        for (beg = 0; beg < n; beg++)
            dfs(beg);
        return res;
    }
};
