#include <numeric>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (const vector<int>& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, 2 * w);
        }

        vector<int> dist(n, numeric_limits<int>::max());
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [dist_x, x] = pq.top();
            pq.pop();

            if (dist_x > dist[x])
                continue;
            if (x == n - 1)
                return dist_x;
            for (auto [y, cost] : graph[x]) {
                int dist_y = dist[x] + cost;
                if (dist_y < dist[y]) {
                    dist[y] = dist_y;
                    pq.emplace(dist_y, y);
                }
            }
        }
        return -1;
    }
};
