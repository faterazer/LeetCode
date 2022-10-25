#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> Q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    dfs(grid, i, j, Q);
                    break;
                }
            }
            if (!Q.empty())
                break;
        }

        int steps = 0;
        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                auto [r, c] = Q.front();
                Q.pop();

                for (const vector<int> d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == -1)
                        continue;
                    if (grid[nr][nc] == 1)
                        return steps;
                    grid[nr][nc] = -1;
                    Q.emplace(nr, nc);
                }
            }
            ++steps;
        }
        return 0;
    }

private:
    void dfs(vector<vector<int>>& grid, int r, int c, queue<pair<int, int>>& Q)
    {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1)
            return;
        Q.emplace(r, c);
        grid[r][c] = -1;
        dfs(grid, r + 1, c, Q);
        dfs(grid, r - 1, c, Q);
        dfs(grid, r, c + 1, Q);
        dfs(grid, r, c - 1, Q);
    }

    vector<vector<int>> dirs { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
};
