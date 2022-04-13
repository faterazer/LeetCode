#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n));
        int val = 0;
        for (int up = 0, down = n - 1, left = 0, right = n - 1; up <= down && left <= right; ++up, --down, ++left, --right) {
            for (int i = left; i <= right; ++i)
                res[up][i] = ++val;
            for (int i = up + 1; i <= down; ++i)
                res[i][right] = ++val;
            for (int i = right - 1; i >= left && up < down; --i)
                res[down][i] = ++val;
            for (int i = down - 1; i > up && left < right; --i)
                res[i][left] = ++val;
        }
        return res;
    }
};
