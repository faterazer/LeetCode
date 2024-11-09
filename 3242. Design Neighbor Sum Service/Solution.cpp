#include <unordered_map>
#include <vector>
using namespace std;

class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid)
    {
        int n = grid.size();
        data.resize(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = grid[i][j];
                for (int d = 0; d < 8; ++d) {
                    int ni = i + directions[d][0], nj = j + directions[d][1];
                    if (0 <= ni && ni < n && 0 <= nj && nj < n)
                        data[v][d / 4] += grid[ni][nj];
                }
            }
        }
    }

    int adjacentSum(int value)
    {
        return data[value][0];
    }

    int diagonalSum(int value)
    {
        return data[value][1];
    }

private:
    static constexpr int directions[8][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 1 }, { -1, 1 }, { -1, -1 }, { 1, -1 } };
    vector<array<int, 2>> data;
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
