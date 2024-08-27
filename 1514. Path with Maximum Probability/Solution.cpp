#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node)
    {
        vector<vector<pair<double, int>>> graph(n);
        for (size_t i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].emplace_back(succProb[i], edges[i][1]);
            graph[edges[i][1]].emplace_back(succProb[i], edges[i][0]);
        }

        priority_queue<pair<double, int>> Q;
        vector<int> visited(n, 0);
        Q.emplace(1.0, start_node);
        while (!Q.empty()) {
            pair<double, int> node = Q.top();
            Q.pop();
            if (node.second == end_node)
                return node.first;
            visited[node.second] = 1;
            for (const pair<double, int> &p : graph[node.second])
                if (!visited[p.second])
                    Q.emplace(node.first * p.first, p.second);
        }
        return 0.0;
    }
};
