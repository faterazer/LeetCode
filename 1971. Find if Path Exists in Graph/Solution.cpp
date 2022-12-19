#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<int> tree(n);
        iota(tree.begin(), tree.end(), 0);
        for (const vector<int> edge : edges) {
            int root_a = findRoot(tree, edge[0]), root_b = findRoot(tree, edge[1]);
            if (root_a != root_b)
                tree[root_b] = root_a;
        }
        return findRoot(tree, source) == findRoot(tree, destination);
    }

private:
    int findRoot(vector<int>& tree, int x)
    {
        if (tree[x] == x)
            return x;
        tree[x] = findRoot(tree, tree[x]);
        return tree[x];
    }
};
