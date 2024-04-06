#include <bit>
#include <vector>
using namespace std;

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent)
    {
        int m = bit_width(static_cast<unsigned>(n));
        ancestors.resize(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
            ancestors[i][0] = parent[i];
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                if (ancestors[j][i - 1] != -1)
                    ancestors[j][i] = ancestors[ancestors[j][i - 1]][i - 1];
    }

    int getKthAncestor(int node, int k)
    {
        int m = bit_width(static_cast<unsigned>(k));
        for (int i = 0; i < m; i++)
            if (k & (1 << i)) {
                node = ancestors[node][i];
                if (node == -1)
                    break;
            }
        return node;
    }

private:
    vector<vector<int>> ancestors;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
