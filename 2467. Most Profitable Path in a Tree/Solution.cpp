#include <algorithm>
#include <climits>
#include <functional>
#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount)
    {
        int n = edges.size() + 1;
        vector<vector<int>> tree(n);
        for (const vector<int>& e : edges) {
            tree[e[0]].emplace_back(e[1]);
            tree[e[1]].emplace_back(e[0]);
        }

        vector<int> bob_path(n, n);
        function<bool(int, int, int)> find_zero = [&](int node, int parent, int steps) -> bool {
            if (node == 0) {
                bob_path[node] = steps;
                return true;
            }
            for (int child : tree[node]) {
                if (child != parent && find_zero(child, node, steps + 1)) {
                    bob_path[node] = steps;
                    return true;
                }
            }
            return false;
        };
        find_zero(bob, -1, 0);

        tree[0].emplace_back(-1); // 避免把 0 当作叶子节点
        function<int(int, int, int, int)> dfs = [&](int node, int parent, int steps, int profit) -> int {
            if (bob_path[node] > steps)
                profit += amount[node];
            else if (bob_path[node] == steps)
                profit += amount[node] / 2;

            if (tree[node].size() == 1)
                return profit;

            int max_profit = INT_MIN;
            for (int child : tree[node])
                if (child != -1 && child != parent)
                    max_profit = max(max_profit, dfs(child, node, steps + 1, profit));
            return max_profit;
        };

        return dfs(0, -1, 0, 0);
    }
};
