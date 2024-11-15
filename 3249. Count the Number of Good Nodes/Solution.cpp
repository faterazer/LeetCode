#include <algorithm>
#include <functional>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges)
    {
        vector<vector<int>> tree(edges.size() + 1);
        for (const vector<int>& e : edges) {
            tree[e[0]].emplace_back(e[1]);
            tree[e[1]].emplace_back(e[0]);
        }

        int ans = 0;
        function<int(int, int)> dfs = [&](int node, int parent) -> int {
            int size = 1, sz0 = 0;
            bool ok = true;
            for (int x : tree[node]) {
                if (x == parent)
                    continue;
                int sz = dfs(x, node);
                if (sz0 == 0)
                    sz0 = sz;
                else if (sz0 != sz)
                    ok = false;
                size += sz;
            }
            ans += ok;
            return size;
        };

        dfs(0, -1);
        return ans;
    }
};
