#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int dp[n][n];
        for (int i = 0; i < n; i++)
            dp[n - 1][i] = matrix[n - 1][i];
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j < n; j++)
                dp[i][j] = matrix[i][j] + min(dp[i + 1][j], min(j == 0 ? INT_MAX : dp[i + 1][j - 1], j == n - 1 ? INT_MAX : dp[i + 1][j + 1]));
        int res = INT_MAX;
        for (int i = 0; i < n; i++)
            res = min(res, dp[0][i]);
        return res;
    }
};
