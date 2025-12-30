#include <algorithm>
#include <array>
#include <vector>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size(), result = 0;
        for (int i = 0; i < m - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                if (grid[i + 1][j + 1] != 5)
                    continue;

                unsigned mask = 0;
                array<int, 3> row_sum {}, col_sum {};
                for (int r = 0; r < 3; ++r) {
                    for (int c = 0; c < 3; ++c) {
                        int x = grid[i + r][j + c];
                        mask |= 1 << x;
                        row_sum[r] += x;
                        col_sum[c] += x;
                    }
                }

                if (mask == (1U << 10) - 2 && row_sum[0] == 15 && row_sum[1] == 15 && col_sum[0] == 15 && col_sum[1] == 15)
                    ++result;
            }
        }
        return result;
    }
};
