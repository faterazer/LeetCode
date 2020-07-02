#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid);
};

int Solution::islandPerimeter(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int islands = 0, neighbours = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                islands++;
                if (i < m - 1 && grid[i + 1][j])
                    neighbours++;
                if (j < n - 1 && grid[i][j + 1])
                    neighbours++;
            }
        }
    }
    return islands * 4 - neighbours * 2;
}
