#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n)
    {
        unordered_map<int, unordered_map<int, int>> E;
        for (const vector<int>& edge : edges)
            E[edge[0]][edge[1]] = E[edge[1]][edge[0]] = edge[2] + 1;

        unordered_map<int, int> seen;
        priority_queue<pair<int, int>> pq;
        pq.emplace(maxMoves, 0);
        while (!pq.empty()) {
            int remain_moves = pq.top().first, node = pq.top().second;
            pq.pop();
            if (!seen.count(node)) {
                seen[node] = remain_moves;
                for (const auto& neighbour : E[node])
                    if (!seen.count(neighbour.first) && remain_moves - neighbour.second >= 0)
                        pq.emplace(remain_moves - neighbour.second, neighbour.first);
            }
        }

        int res = seen.size();
        for (const vector<int>& edge : edges) {
            int a = seen.count(edge[0]) ? seen[edge[0]] : 0;
            int b = seen.count(edge[1]) ? seen[edge[1]] : 0;
            res += min(a + b, edge[2]);
        }
        return res;
    }
};
