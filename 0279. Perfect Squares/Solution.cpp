#include <climits>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Time complexity: O(n√n)
     * Space complexity: O(n)
     */
    int numSquares_MK1(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
        return dp[n];
    }

    /**
     * 四平方和定理
     * Time complexity: O(√n)
     * Space complexity: O(1)
     */
    int numSquares_MK2(int n)
    {
        if (isPerfectSquare(n))
            return 1;
        if (check(n))
            return 4;
        for (int i = 1; i * i <= n; i++)
            if (isPerfectSquare(n - i * i))
                return 2;
        return 3;
    }

private:
    bool isPerfectSquare(int x)
    {
        int y = sqrt(x);
        return y * y == x;
    }

    bool check(int x)
    {
        while (x % 4 == 0)
            x /= 4;
        return x % 8 == 7;
    }
};
