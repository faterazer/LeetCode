#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0)), atlantic(pacific);
        for (int i = 0; i < n; ++i) {
            dfs(heights, 0, i, pacific);
            dfs(heights, m - 1, i, atlantic);
        }
        for (int i = 0; i < m; ++i) {
            dfs(heights, i, 0, pacific);
            dfs(heights, i, n - 1, atlantic);
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({ i, j });
        return res;
    }

private:
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<int>>& visited)
    {
        int m = heights.size(), n = heights[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c])
            return;
        visited[r][c] = 1;
        if (r > 0 && heights[r][c] <= heights[r - 1][c])
            dfs(heights, r - 1, c, visited);
        if (r < m - 1 && heights[r][c] <= heights[r + 1][c])
            dfs(heights, r + 1, c, visited);
        if (c > 0 && heights[r][c] <= heights[r][c - 1])
            dfs(heights, r, c - 1, visited);
        if (c < n - 1 && heights[r][c] <= heights[r][c + 1])
            dfs(heights, r, c + 1, visited);
    }
};
