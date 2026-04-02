#include <array>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins)
    {
        int n = coins[0].size(), NINF = numeric_limits<int>::min();
        vector f(n + 1, array<int, 3> { NINF / 2, NINF / 2, NINF / 2 });
        f[1] = { 0, 0, 0 };
        for (const vector<int>& row : coins) {
            for (int j = 0; j < n; ++j) {
                int x = row[j];
                f[j + 1][2] = max({ f[j][2] + x, f[j + 1][2] + x, f[j][1], f[j + 1][1] });
                f[j + 1][1] = max({ f[j][1] + x, f[j + 1][1] + x, f[j][0], f[j + 1][0] });
                f[j + 1][0] = max(f[j][0], f[j + 1][0]) + x;
            }
        }
        return f[n][2];
    }
};
