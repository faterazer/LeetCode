#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size(), size = m * n;
        k %= size;
        if (!k)
            return grid;
        if (k % n == 0) {
            int x = k / n;
            reverse(grid.rbegin(), grid.rbegin() + x);
            reverse(grid.rbegin() + x, grid.rend());
            reverse(grid.begin(), grid.end());
            return grid;
        }
        gridReverse(grid, 0, size - k - 1);
        gridReverse(grid, size - k, size - 1);
        gridReverse(grid, 0, size - 1);
        return grid;
    }

private:
    void gridReverse(vector<vector<int>> &grid, int beg, int end)
    {
        int n = grid[0].size();
        for (; beg < end; beg++, end--)
            swap(grid[beg / n][beg % n], grid[end / n][end % n]);
    }
};
