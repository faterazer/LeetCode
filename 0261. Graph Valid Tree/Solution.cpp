#include <vector>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        vector<int> tree(n, -1);
        for (const vector<int>& e : edges) {
            int a = e[0], b = e[1];
            int roota = findRoot(tree, a), rootb = findRoot(tree, b);
            if (roota == rootb)
                return false;
            tree[rootb] = roota;
        }
        return edges.size() == n - 1;
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
