#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if (n == 1)
            return { 0 };

        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for (const vector<int>& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        queue<int> Q;
        for (int i = 0; i < n; i++)
            if (degree[i] == 1)
                Q.emplace(i);

        int remain = n;
        while (remain > 2) {
            int size = Q.size();
            remain -= size;
            for (int i = 0; i < size; i++) {
                int node = Q.front();
                Q.pop();
                for (int neighbour : adj[node])
                    if (--degree[neighbour] == 1)
                        Q.emplace(neighbour);
            }
        }

        vector<int> res;
        while (!Q.empty()) {
            res.emplace_back(Q.front());
            Q.pop();
        }
        return res;
    }
};
