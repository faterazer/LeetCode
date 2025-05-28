#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k)
    {
        vector<vector<int>> tree1 = buildTree(edges1), tree2 = buildTree(edges2);
        int max2 = 0;
        for (size_t i = 0; i < tree2.size(); ++i)
            max2 = max(max2, dfs(tree2, i, -1, k - 1));
        vector<int> ans(tree1.size());
        for (size_t i = 0; i < tree1.size(); ++i)
            ans[i] = dfs(tree1, i, -1, k) + max2;
        return ans;
    }

private:
    vector<vector<int>> buildTree(const vector<vector<int>>& edges)
    {
        int size = edges.size() + 1;
        vector<vector<int>> tree(size);
        for (const vector<int>& edge : edges) {
            tree[edge[0]].emplace_back(edge[1]);
            tree[edge[1]].emplace_back(edge[0]);
        }
        return tree;
    }

    int dfs(const vector<vector<int>>& tree, int node, int parent, int k)
    {
        if (k < 0)
            return 0;
        int cnt = 1;
        for (int child : tree[node])
            if (child != parent)
                cnt += dfs(tree, child, node, k - 1);
        return cnt;
    }
};
