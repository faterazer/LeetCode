#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int N = grid.size(), area = 0;
        for (int i = 0; i < N; i++) {
            int rowMax = 0, colMax = 0;
            for (int j = 0; j < N; j++) {
                area += grid[i][j] > 0;
                rowMax = max(rowMax, grid[i][j]);
                colMax = max(colMax, grid[j][i]);
            }
            area += rowMax + colMax;
        }
        return area;
    }
};
