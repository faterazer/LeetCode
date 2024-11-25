#include <algorithm>
#include <queue>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (const vector<int>& t : times)
            graph[t[0] - 1].emplace_back(t[1] - 1, t[2]);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k - 1);
        vector<int> dis(n, INT_MAX);
        dis[k - 1] = 0;

        while (!pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();

            if (du > dis[u])
                continue;

            for (const auto& [v, d] : graph[u]) {
                int new_dis = du + d;
                if (new_dis < dis[v]) {
                    dis[v] = new_dis;
                    pq.emplace(new_dis, v);
                }
            }
        }

        int mx = ranges::max(dis);
        return mx == INT_MAX ? -1 : mx;
    }
};
