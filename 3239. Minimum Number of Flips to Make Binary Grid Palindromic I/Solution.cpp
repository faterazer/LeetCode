#include <vector>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int row_ans = 0, col_ans = 0;
        for (int i = 0; i < m; ++i)
            for (int left = 0, right = n - 1; left < right; ++left, --right)
                row_ans += grid[i][left] != grid[i][right];

        for (int j = 0; j < n; ++j)
            for (int left = 0, right = m - 1; left < right; ++left, --right)
                col_ans += grid[left][j] != grid[right][j];

        return min(row_ans, col_ans);
    }
};
