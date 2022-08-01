#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        long long numerator = 1, denominator = 1;
        for (int x = max(m, n), y = min(m, n) - 1; y > 0; ++x, --y) {
            numerator *= x;
            denominator *= y;
            int g = gcd(numerator, denominator);
            numerator /= g;
            denominator /= g;
        }
        return numerator / denominator;
    }
};
