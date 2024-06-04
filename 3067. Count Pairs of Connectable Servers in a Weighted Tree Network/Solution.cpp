#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed)
    {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> graph(n);
        for (const vector<int>& e : edges) {
            graph[e[0]].emplace_back(make_pair(e[1], e[2]));
            graph[e[1]].emplace_back(make_pair(e[0], e[2]));
        }

        function<int(int, int, int)> dfs = [&](int x, int parent, int dist) -> int {
            int r = dist % signalSpeed == 0;
            for (const pair<int, int>& p : graph[x])
                if (p.first != parent)
                    r += dfs(p.first, x, dist + p.second);
            return r;
        };

        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            if (graph[i].size() < 2)
                continue;

            int sum = 0;
            for (pair<int, int> &p : graph[i]) {
                int cnt = dfs(p.first, i, p.second);
                res [i] += sum * cnt;
                sum += cnt;
            }
        }
        return res;
    }
};
