#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid)
    {
        int n = grid[0].size();
        vector<int> col_sum(n, -1); // 提前减 1
        for (const vector<int>& row : grid)
            for (int j = 0; j < n; j++)
                col_sum[j] += row[j];

        long long res = 0;
        for (const vector<int>& row : grid) {
            int row_sum = reduce(row.begin(), row.end(), -1);
            for (int j = 0; j < n; j++)
                if (row[j])
                    res += row_sum * col_sum[j];
        }
        return res;
    }
};
