#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target)
    {
        vector<vector<int>> tree(n + 1);
        tree[1] = { 0 };
        for (const vector<int>& e : edges) {
            tree[e[0]].emplace_back(e[1]);
            tree[e[1]].emplace_back(e[0]);
        }

        double choices = dfs(tree, 0, 1, target, t);
        return choices ? 1 / choices : 0;
    }

private:
    int dfs(const vector<vector<int>>& tree, int partent, int vertice, int target, int t)
    {
        if (!t)
            return vertice == target;
        if (vertice == target)
            return tree[vertice].size() == 1;

        for (int neighbour : tree[vertice]) {
            if (neighbour == partent)
                continue;
            int choices = dfs(tree, vertice, neighbour, target, t - 1);
            if (choices)
                return (tree[vertice].size() - 1) * choices;
        }
        return 0;
    }
};
