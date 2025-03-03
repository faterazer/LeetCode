#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int palindromePartition(string s, int k)
    {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int j = 0; j < n; ++j)
            for (int i = 0; i <= j; ++i)
                cost[i][j] = (s[i] != s[j]) + (j - i < 2 ? 0 : cost[i + 1][j - 1]);
        
        vector<int> f(cost[0]);
        for (int i = 1; i < k; ++i) {
            for (int r = n - 1; r >= i; --r) {
                int tmp = INT_MAX;
                for (int l = i; l <= r; ++l)
                    tmp = min(tmp, f[l - 1] + cost[l][r]);
                f[r] = tmp;
            }
        }
        return f.back();
    }
};
