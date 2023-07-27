#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid)
    {
        for (vector<int>& row : grid)
            sort(row.begin(), row.end());

        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int j = 0; j < n; j++) {
            int mx = grid[0][j];
            for (int i = 0; i < m; i++)
                mx = max(mx, grid[i][j]);
            res += mx;
        }
        return res;
    }
};
