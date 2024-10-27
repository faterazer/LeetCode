#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1, -1), ans;

        function<int(int)> findRoot = [&](int x) -> int {
            if (parent[x] == -1)
                return x;
            parent[x] = findRoot(parent[x]);
            return parent[x];
        };

        for (const vector<int>& e : edges) {
            int root0 = findRoot(e[0]), root1 = findRoot(e[1]);
            if (root0 == root1)
                ans = e;
            else
                parent[root1] = root0;
        }
        return ans;
    }
};
