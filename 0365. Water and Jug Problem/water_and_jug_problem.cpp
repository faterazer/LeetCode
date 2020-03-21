#include <numeric>
using namespace std;

class Solution
{
public:
    bool canMeasureWater(int x, int y, int z);
};

bool Solution::canMeasureWater(int x, int y, int z)
{
    if (x + y < z)
        return false;
    if (!x || !y)
        return z == 0 || x + y == z;
    return z % gcd(x, y) == 0;
}
