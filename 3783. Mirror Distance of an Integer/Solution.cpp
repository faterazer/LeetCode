#include <cmath>

class Solution {
public:
    int mirrorDistance(int n)
    {
        int rn = 0;
        for (int x = n; x; x /= 10)
            rn = rn * 10 + x % 10;
        return abs(n - rn);
    }
};
