#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size(), ans = 0;

        function<int(int, int)> dfs = [&](int r, int c) -> int {
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] <= 0)
                return 0;
            grid[r][c] *= -1;
            return -grid[r][c] + dfs(r - 1, c) + dfs(r + 1, c) + dfs(r, c - 1) + dfs(r, c + 1);
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] > 0)
                    ans = max(ans, dfs(i, j));
        return ans;
    }
};
