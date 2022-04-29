#include <vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        vector<int> tree(graph.size(), -1);
        int n = graph.size();
        for (int i = 0; i < n; ++i) {
            if (graph[i].empty())
                continue;
            int root1 = findRoot(tree, i), root2 = findRoot(tree, graph[i][0]);
            for (const int &e : graph[i]) {
                int root = findRoot(tree, e);
                if (root1 == root)
                    return false;
                if (root2 != root)
                    tree[root] = root2;
            }
        }
        return true;
    }

private:
    int findRoot(vector<int>& tree, int x)
    {
        if (tree[x] == -1)
            return x;

        int root = findRoot(tree, tree[x]);
        tree[x] = root;
        return root;
    }
};
