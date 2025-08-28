#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    std::vector<std::vector<int>> sortMatrix(std::vector<std::vector<int>>& grid)
    {
        int n = grid.size();
        for (int k = 0; k < 2 * n - 1; ++k) {
            int r_start = (k < n) ? n - 1 - k : 0;
            int c_start = (k < n) ? 0 : k - n + 1;

            std::vector<int> buffer;
            int r = r_start, c = c_start;
            while (r < n && c < n)
                buffer.push_back(grid[r++][c++]);

            if (k < n) // 左下三角 + 主对角线 (i - j >= 0)
                std::ranges::sort(buffer, std::ranges::greater {});
            else // 右上三角 (i - j < 0)
                std::ranges::sort(buffer);

            r = r_start, c = c_start;
            for (int val : buffer)
                grid[r++][c++] = val;
        }
        return grid;
    }
};
