#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target)
    {
        if (target < n || target > n * k)
            return 0;

        int MOD = 1e9 + 7;
        vector<int> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = min(target, i * k); j >= 0; j--) {
                f[j] = 0;
                for (int w = 1; w <= k && j - w >= 0; w++)
                    f[j] = (f[j] + f[j - w]) % MOD;
            }
        }
        return f.back();
    }
};
