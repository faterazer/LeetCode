#include <vector>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> pre_sum(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                pre_sum[i + 1][j + 1] = pre_sum[i][j + 1] + pre_sum[i + 1][j] - pre_sum[i][j] + mat[i][j];

        // 左上角 (r1, c1), 右下角 (r2, c2)
        auto query = [&](int r1, int c1, int r2, int c2) -> int {
            return pre_sum[r2 + 1][c2 + 1] - pre_sum[r2 + 1][c1] - pre_sum[r1][c2 + 1] + pre_sum[r1][c1];
        };

        int max_side = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                while (i + max_side < m && j + max_side < n && query(i, j, i + max_side, j + max_side) <= threshold)
                    ++max_side;
        return max_side;
    }
};
