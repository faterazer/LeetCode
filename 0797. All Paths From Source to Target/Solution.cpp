#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> cur;
        dfs(graph, 0, n - 1, res, cur);
        return res;
    }

private:
    void dfs(const vector<vector<int>>& graph, int source, int dest, vector<vector<int>>& res, vector<int>& cur)
    {
        cur.emplace_back(source);
        if (source == dest)
            res.emplace_back(cur);
        else {
            for (const int& neighbour : graph[source])
                dfs(graph, neighbour, dest, res, cur);
        }
        cur.pop_back();
    }
};
