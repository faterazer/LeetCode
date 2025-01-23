#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> row_sum(m, 0), col_sum(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row_sum[i] += grid[i][j];
                col_sum[j] += grid[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans += grid[i][j] && (row_sum[i] > 1 || col_sum[j] > 1);
        return ans;
    }
};
