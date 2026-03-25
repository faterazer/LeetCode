#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid)
    {
        long long total_sum = 0;
        for (const vector<int>& row : grid)
            total_sum += reduce(row.begin(), row.end(), 0LL);

        long long s = 0;
        for (const vector<int>& row : grid) {
            s += reduce(row.begin(), row.end(), 0LL);
            if (s * 2 == total_sum)
                return true;
        }

        int m = grid.size(), n = grid[0].size();
        s = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i)
                s += grid[i][j];
            if (s * 2 == total_sum)
                return true;
        }
        return false;
    }
};
