#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int a = res[j] >= 0 ? res[j] / 10 : -res[j];
                int b = grid[i][j] >= 0 ? grid[i][j] / 10 : -grid[i][j];
                if (a < b)
                    res[j] = grid[i][j];
            }
        }

        for (int i = 0; i < n; i++)
            res[i] = to_string(res[i]).length();
        return res;
    }
};
