#include <vector>
using namespace std;

class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid);
};

int Solution::surfaceArea(vector<vector<int>> &grid)
{
    int surface = 0, N = grid.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) {
                surface += (grid[i][j] << 2) + 2;
                surface -= i > 0 ? min(grid[i-1][j], grid[i][j]) << 1 : 0;
                surface -= j > 0 ? min(grid[i][j-1], grid[i][j]) << 1 : 0;
            }
        }
    }
    return surface;
}
