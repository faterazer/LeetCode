#include <vector>
using namespace std;

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges)
    {
        int n = edges.size() + 1;
        vector<vector<int>> tree(n + 1);
        for (const vector<int>& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        auto max_depth = [&](this auto&& self, int x, int parent) -> int {
            int d = 0;
            for (int y : tree[x])
                if (y != parent)
                    d = max(d, self(y, x) + 1);
            return d;
        };

        int d = max_depth(1, 0), result = 1;
        for (int i = 1; i < d; ++i)
            result = (result << 1) % MOD;
        return result;
    }

private:
    const int MOD = 1000000007;
};
