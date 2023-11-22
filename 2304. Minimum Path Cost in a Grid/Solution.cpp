#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(grid[0]);
        for (int i = 0; i < m - 1; i++) {
            vector<int> buff(n, INT_MAX);
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    buff[k] = min(buff[k], res[j] + moveCost[grid[i][j]][k] + grid[i + 1][k]);
            res = buff;
        }
        return *min_element(res.begin(), res.end());
    }
};
