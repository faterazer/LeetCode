#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    expand(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    void expand(vector<vector<char>>& grid, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1')
            return;
        grid[r][c] = '2';
        expand(grid, r + 1, c);
        expand(grid, r - 1, c);
        expand(grid, r, c + 1);
        expand(grid, r, c - 1);
    }
};
