#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] || grid[m - 1][n - 1])
            return -1;
        if (m == 1 && n == 1 && grid[0][0] == 0)
            return 1;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> directions { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };
        queue<vector<int>> frontier;
        frontier.push({ 0, 0 });
        int steps = 0;
        while (!frontier.empty()) {
            ++steps;
            int size = frontier.size();
            for (int i = 0; i < size; ++i) {
                int r = frontier.front()[0], c = frontier.front()[1];
                frontier.pop();
                for (const vector<int>& d : directions) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] || visited[nr][nc])
                        continue;
                    if (nr == m - 1 && nc == n - 1)
                        return steps + 1;
                    visited[nr][nc] = 1;
                    frontier.push({ nr, nc });
                }
            }
        }
        return -1;
    }
};
