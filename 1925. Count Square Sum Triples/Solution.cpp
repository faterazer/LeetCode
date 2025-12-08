#include <numeric>
using namespace std;

class Solution {
public:
    int countTriples(int n)
    {
        int result = 0;
        for (int u = 3; u * u < n * 2; u += 2)
            for (int v = 1; v < u && u * u + v * v <= n * 2; v += 2)
                if (gcd(u, v) == 1)
                    result += n * 2 / (u * u + v * v);
        return result * 2;
    }
};
