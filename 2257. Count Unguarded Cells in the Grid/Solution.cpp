#include <array>
#include <vector>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        int ans = m * n - guards.size() - walls.size();
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (const vector<int>& guard : guards)
            grid[guard[0]][guard[1]] = -1;
        for (const vector<int>& wall : walls)
            grid[wall[0]][wall[1]] = -1;

        for (const vector<int>& guard : guards) {
            int x = guard[0], y = guard[1];
            for (const auto& [dx, dy] : DIRECTIONS) {
                for (int nx = x + dx, ny = y + dy; nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != -1; nx += dx, ny += dy) {
                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 2;
                        --ans;
                    }
                }
            }
        }
        return ans;
    }

private:
    static constexpr int DIRECTIONS[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
};
