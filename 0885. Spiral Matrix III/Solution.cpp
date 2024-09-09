#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> res{{rStart, cStart}};
        for (int up = rStart - 1, down = rStart + 1, left = cStart - 1, right = cStart + 1; up >= 0 || down < rows || left >= 0 || right < cols; up--, down++, left--, right++) {
            for (int i = up + 1; i <= down && right < cols; i++)
                if (i >= 0 && i < rows)
                    res.push_back({i, right});
            for (int i = right - 1; i >= left && down < rows; i--)
                if (i >= 0 && i < cols)
                    res.push_back({down, i});
            for (int i = down - 1; i >= up && left >= 0; i--)
                if (i >= 0 && i < rows)
                    res.push_back({i, left});
            for (int i = left + 1; i <= right && up >= 0; i++)
                if (i >= 0 && i < cols)
                    res.push_back({up, i});
        }
        return res;
    }
};
