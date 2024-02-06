#include <vector>
using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n)
    {
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int min_val = INT_MAX;
            for (int j = 1; j * j <= i; j++)
                min_val = min(min_val, f[i - j * j]);
            f[i] = n - min_val;
        }
        return 2 * f[n] > n;
    }
};
