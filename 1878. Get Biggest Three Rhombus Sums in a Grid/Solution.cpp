#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> result(3);

        auto update = [&](int x) -> void {
            if (x > result[0]) {
                result[2] = result[1];
                result[1] = result[0];
                result[0] = x;
            } else if (x < result[0] && x > result[1]) {
                result[2] = result[1];
                result[1] = x;
            } else if (x < result[1] && x > result[2])
                result[2] = x;
        };

        vector<vector<int>> dia1_pre_sum(m + 1, vector<int>(n + 1)), dia2_pre_sum(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dia1_pre_sum[i + 1][j + 1] = dia1_pre_sum[i][j] + grid[i][j];
                dia2_pre_sum[i + 1][j] = dia2_pre_sum[i][j + 1] + grid[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                update(grid[i][j]);
                for (int k = 1; i + 2 * k < m && j - k >= 0 && j + k < n; ++k) {
                    int x = dia2_pre_sum[i + 1 + k][j - k] - dia2_pre_sum[i][j + 1];
                    x += dia1_pre_sum[i + 1 + 2 * k][j + 1] - dia1_pre_sum[i + 1 + k][j + 1 - k];
                    x += dia2_pre_sum[i + 2 * k][j + 1] - dia2_pre_sum[i + k][j + k + 1];
                    x += dia1_pre_sum[i + k][j + k] - dia1_pre_sum[i + 1][j + 1];
                    update(x);
                }
            }
        }
        while (result.back() == 0)
            result.pop_back();
        return result;
    }
};
