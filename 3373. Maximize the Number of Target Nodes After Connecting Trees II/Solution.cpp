#include <algorithm>
#include <functional>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2)
    {
        auto [_, cnt2] = buildTree(edges2);
        int max2 = max(cnt2[0], cnt2[1]);

        auto [tree1, cnt1] = buildTree(edges1);
        vector<int> ans(tree1.size(), max2);
        function<void(int, int, int)> dfs = [&](int node, int parent, int d) -> void {
            ans[node] += cnt1[d];
            for (int child : tree1[node])
                if (child != parent)
                    dfs(child, node, d ^ 1);
        };
        dfs(0, -1, 0);
        return ans;
    }

private:
    pair<vector<vector<int>>, array<int, 2>> buildTree(const vector<vector<int>>& edges)
    {
        vector<vector<int>> tree(edges.size() + 1);
        for (const vector<int> &edge : edges) {
            tree[edge[0]].emplace_back(edge[1]);
            tree[edge[1]].emplace_back(edge[0]);
        }

        array<int, 2> cnt{};
        function<void(int, int, int)> dfs = [&](int x, int parent, int d) -> void {
            ++cnt[d];
            for (int child : tree[x])
                if (child != parent)
                    dfs(child, x, d ^ 1);
        };
        dfs(0, -1, 0);
        return pair(tree, cnt);
    }
};
