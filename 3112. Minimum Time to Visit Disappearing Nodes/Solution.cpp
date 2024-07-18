#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (const vector<int> &e : edges) {
            graph[e[0]].emplace_back(e[1], e[2]);
            graph[e[1]].emplace_back(e[0], e[2]);
        }

        vector<int> dist(n, -1);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [dx, x] = pq.top();
            pq.pop();

            if (dx > dist[x])
                continue;

            for (auto [y, d] : graph[x]) {
                int new_dist = dx + d;
                if (new_dist < disappear[y] && (dist[y] == -1 || new_dist < dist[y])) {
                    dist[y] = new_dist;
                    pq.emplace(new_dist, y);
                }
            }
        }
        return dist;
    }
};
