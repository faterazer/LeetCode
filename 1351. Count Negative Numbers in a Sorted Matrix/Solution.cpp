#include <vector>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int i = 0, j = grid[0].size() - 1, res = 0;
        while (i < grid.size() && j >= 0) {
            while (j >= 0 && grid[i][j] < 0)
                j--;
            res += grid[0].size() - j - 1;
            i++;
        }
        return res + (grid.size() - i) * grid[0].size();
    }
};
