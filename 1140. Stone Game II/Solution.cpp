#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles)
    {
        int suf_sum = 0, n = piles.size(), f[n][n / 2 + 2];
        for (int i = n - 1; i >= 0; i--) {
            suf_sum += piles[i];
            for (int m = 1; m <= i / 2 + 1; m++) {
                if (i + m * 2 >= n)
                    f[i][m] = suf_sum;
                else {
                    int min_val = INT_MAX;
                    for (int x = 1; x <= m * 2; x++)
                        min_val = min(min_val, f[i + x][max(m, x)]);
                    f[i][m] = suf_sum - min_val;
                }
            }
        }
        return f[0][1];
    }
};
