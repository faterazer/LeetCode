#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    double soupServings(int n)
    {
        n = ceil(n / 25.0);
        if (n >= 179)
            return 1.0;
        vector<vector<double>> memo(179, vector<double>(179, -1.0));
        return dfs(n, n, memo);
    }

private:
    double dfs(double a, double b, vector<vector<double>>& memo)
    {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1.0;
        if (b <= 0)
            return 0.0;
        if (memo[a][b] < 0.0)
            memo[a][b] = 0.25 * (dfs(a - 4, b, memo) + dfs(a - 3, b - 1, memo) + dfs(a - 2, b - 2, memo) + dfs(a - 1, b - 3, memo));
        return memo[a][b];
    }
};
