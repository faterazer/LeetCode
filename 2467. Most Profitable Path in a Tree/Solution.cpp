#include <algorithm>
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

        unordered_map<int, int> bob_path { { bob, 0 } };
        vector<int> visited(n, 0);
        function<bool(int, int)> find_zero = [&](int node, int steps) -> bool {
            visited[node] = 1;
            if (node == 0) {
                bob_path[node] = steps;
                return true;
            }
            for (int child : tree[node]) {
                if (visited[child])
                    continue;
                if (find_zero(child, steps + 1)) {
                    bob_path[node] = steps;
                    return true;
                }
            }
            return false;
        };
        find_zero(bob, 0);
        
        ranges::fill(visited, 0);
        function<int(int, int, int)> dfs = [&](int node, int steps, int profit) -> int {
            visited[node] = 1;
            if (bob_path.contains(node)) {
                if (bob_path[node] == steps)
                    profit += amount[node] / 2;
                else if (bob_path[node] > steps)
                    profit += amount[node];
            } else
                profit += amount[node];


            int max_profit = INT_MIN, cnt = 0;
            for (int child : tree[node]) {
                if (!visited[child]) {
                    ++cnt;
                    max_profit = max(max_profit, dfs(child, steps + 1, profit));
                }
            }
            return cnt ? max_profit : profit;
        };

        return dfs(0, 0, 0);
    }
};
