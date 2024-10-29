#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1, -1);
        vector<int> dsu(n + 1, -1);
        vector<int> conflict, cycle;

        function<int(int)> findRoot = [&](int x) -> int {
            if (dsu[x] == -1)
                return x;
            dsu[x] = findRoot(dsu[x]);
            return dsu[x];
        };

        for (const vector<int>& e : edges) {
            int u = e[0], v = e[1];
            if (parent[v] != -1)
                conflict = e;
            else {
                parent[v] = u;
                int root_u = findRoot(u), root_v = findRoot(v);
                if (root_u == root_v)
                    cycle = e;
                else
                    dsu[root_v] = root_u;
            }
        }

        if (cycle.empty())
            return conflict;
        if (conflict.empty())
            return cycle;
        return { parent[conflict[1]], conflict[1] };
    }
};
