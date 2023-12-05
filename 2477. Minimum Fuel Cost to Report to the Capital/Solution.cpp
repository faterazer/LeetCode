#include <vector>
using namespace std;

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats)
    {
        int n = roads.size() + 1;
        vector<vector<int>> graph(n);
        for (const vector<int>& road : roads) {
            graph[road[0]].emplace_back(road[1]);
            graph[road[1]].emplace_back(road[0]);
        }

        long long res = 0;
        function<int(int, int)> dfs = [&](int node, int parent) -> int {
            int size = 1;
            for (int child : graph[node]) {
                if (child != parent)
                    size += dfs(child, node);
            }
            if (node != 0)
                res += (size - 1) / seats + 1;
            return size;
        };

        dfs(0, -1);
        return res;
    }
};
