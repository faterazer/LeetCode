#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> row_sum(m, 0), col_sum(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row_sum[i] += 2 * grid[i][j] - 1;
                col_sum[j] += 2 * grid[i][j] - 1;
            }
        }

        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res[i][j] = row_sum[i] + col_sum[j];
        return res;
    }
};
