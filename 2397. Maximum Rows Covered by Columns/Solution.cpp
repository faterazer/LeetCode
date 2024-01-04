#include <bit>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<unsigned> masks(m, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                masks[i] |= matrix[i][j] << j;

        int res = 0;
        unsigned x = (1 << numSelect) - 1;
        while (x < (1 << n)) {
            int covered_rows = 0;
            for (unsigned row : masks)
                if ((row & x) == row)
                    covered_rows++;
            res = max(res, covered_rows);

            unsigned low_bit = x & -x;
            x = (x + low_bit) | ((x ^ (x + low_bit)) / low_bit >> 2);
        }
        return res;
    }
};
