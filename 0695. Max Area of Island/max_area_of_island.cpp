#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid);

private:
    int area(vector<vector<int>> &grid, int i, int j);
};

int Solution::maxAreaOfIsland(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j])
                ans = max(area(grid, i, j), ans);
    return ans;
}

int Solution::area(vector<vector<int>> &grid, int i, int j)
{
    int ans = 0;
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> Q;
    Q.push({i, j});
    grid[i][j] = 0;
    while (!Q.empty())
    {
        ans++;
        pair<int, int> index = Q.front();
        Q.pop();
        for (const pair<int, int> &dir : dirs)
        {
            int ni = index.first + dir.first;
            int nj = index.second + dir.second;
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || !grid[ni][nj])
                continue;
            grid[ni][nj] = 0;
            Q.push({ni, nj});
        }
    }
    return ans;
}
