#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs_MK1(int n); // Brute Force
    int climbStairs_MK2(int n); // Recursion with Memoization
    int climbStairs_MK3(int n); // Dynamic Programming
    int climbStairs_MK4(int n); // Fibonacci Number
    int climbStairs_MK5(int n); // Binets Method
    int climbStairs_MK6(int n); // Fibonacci Formula
    int climbStairs_MK7(int n); // Use Combination of Probability Theory
private:
    int comb(int n, int m);
    int gcd(int a, int b);
    int climbStairs(int i, int n);
    int climbStairs(int i, int n, vector<int>& memo);
    vector<vector<long long>> matrixMultiply(const vector<vector<long long>>& a, const vector<vector<long long>>& b);
};

int Solution::climbStairs(int i, int n)
{
    if (i > n)
        return 0;
    if (i == n)
        return 1;
    return climbStairs(i + 1, n) + climbStairs(i + 2, n);
}

// Brute Force
int Solution::climbStairs_MK1(int n)
{
    return climbStairs(0, n);
}

int Solution::climbStairs(int i, int n, vector<int>& memo)
{
    if (i > n)
        return 0;
    if (i == n)
        return 1;
    if (memo[i] > 0)
        return memo[i];
    memo[i] = climbStairs(i + 1, n, memo) + climbStairs(i + 2, n, memo);
    return memo[i];
}

int Solution::climbStairs_MK2(int n)
{
    vector<int> memo(n, 0);
    return climbStairs(0, n, memo);
}

// Dynamic Programming
int Solution::climbStairs_MK3(int n)
{
    vector<int> dp;
    dp.resize(n + 1);
    // For 0 or 1 stair, only one way to climb
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// Fibonacci Number
int Solution::climbStairs_MK4(int n)
{
    if (n == 1 || n == 2)
        return n;

    int first = 1, second = 2;
    for (int i = 3; i <= n; i++) {
        second = first + second;
        first = second - first;
    }
    return second;
}

vector<vector<long long>> Solution::matrixMultiply(const vector<vector<long long>>& a, const vector<vector<long long>>& b)
{
    vector<vector<long long>> ans { { 0, 0 }, { 0, 0 } };
    for (size_t i = 0; i != a.size(); i++)
        for (size_t j = 0; j != a.size(); j++)
            for (size_t k = 0; k != a.size(); k++)
                ans[i][j] += a[i][k] * b[k][j];
    return ans;
}

// Binets Method
// To understand more pow details, click https://zhuanlan.zhihu.com/p/67977216 (in Chinese)
// 为了快速求幂运算，使用了二分求幂，具体可见 https://zhuanlan.zhihu.com/p/67977216
int Solution::climbStairs_MK5(int n)
{
    // Use long long to tackle int overflow.
    // 为了避免溢出，使用 long long 类型
    vector<vector<long long>> a = { { 1, 1 }, { 1, 0 } };
    vector<vector<long long>> ans = { { 1, 0 }, { 0, 1 } };
    while (n) {
        if (n % 2 == 1)
            ans = matrixMultiply(ans, a);
        a = matrixMultiply(a, a);
        n /= 2;
    }
    return ans[0][0];
}

// Fibonacci Formula
int Solution::climbStairs_MK6(int n)
{
    double sqrt5 = sqrt(5);
    double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
    return static_cast<int>(fibn / sqrt5);
}

// Use Combination of Probability Theory
int Solution::climbStairs_MK7(int n)
{
    int ans = 0;
    for (int m = 0; m <= n; m++, n--)
        ans += comb(n, m);
    return ans;
}

int Solution::comb(int n, int m)
{
    int numerator = 1;
    int denominator = 1;
    while (m) {
        numerator *= n;
        denominator *= m;
        int t = gcd(numerator, denominator);
        numerator /= t;
        denominator /= t;
        n--;
        m--;
    }
    return numerator / denominator;
}

int Solution::gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
