#include <vector>
using namespace std;

class Solution {
public:
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<double>> f(n, vector<double>(n, 1.0));
        while (k--) {
            vector<vector<double>> next_f(n, vector<double>(n, 0.0));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (auto [di, dj] : directions) {
                        int ni = i + di, nj = j + dj;
                        if (0 <= ni && ni < n && 0 <= nj && nj < n)
                            next_f[i][j] += 1.0 / 8.0 * f[ni][nj];
                    }
                }
            }
            f = std::move(next_f);
        }
        return f[row][column];
    }

private:
    static constexpr int directions[8][2] = { { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 }, { -2, -1 }, { -1, -2 } };
};
