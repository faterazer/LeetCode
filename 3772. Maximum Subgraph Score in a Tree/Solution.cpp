#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good)
    {
        vector<vector<int>> graph(n);
        for (const vector<int>& e : edges) {
            int x = e[0], y = e[1];
            graph[x].emplace_back(y);
            graph[y].emplace_back(x);
        }
        vector<int> result(n);

        auto dfs = [&](this auto&& self, int node, int parent) -> void {
            result[node] = good[node] ? 1 : -1;
            for (int neighbour : graph[node]) {
                if (neighbour != parent) {
                    self(neighbour, node);
                    result[node] += max(result[neighbour], 0);
                }
            }
        };
        dfs(0, -1);

        auto reroot = [&](this auto&& self, int node, int parent) -> void {
            for (int neighbour : graph[node]) {
                if (neighbour != parent) {
                    result[neighbour] += max(result[node] - max(result[neighbour], 0), 0);
                    self(neighbour, node);
                }
            }
        };
        reroot(0, -1);

        return result;
    }
};
