#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime)
    {
        int n = values.size();
        vector<vector<pair<int, int>>> graph(n);
        for (const vector<int>& e : edges) {
            graph[e[0]].emplace_back(e[1], e[2]);
            graph[e[1]].emplace_back(e[0], e[2]);
        }

        int res = 0;
        vector<int> visited(n, 0);
        function<void(int, int, int)> dfs = [&](int node, int remainingTime, int curValues) -> void {
            if (visited[node] == 0)
                curValues += values[node];
            visited[node]++;

            if (node == 0)
                res = max(res, curValues);

            for (const auto& [neighbour, cost] : graph[node])
                if (cost <= remainingTime)
                    dfs(neighbour, remainingTime - cost, curValues);

            visited[node]--;
            if (visited[node] == 0)
                curValues -= values[node];
        };

        dfs(0, maxTime, 0);
        return res;
    }
};
