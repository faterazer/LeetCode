#include <cmath>
#include <limits>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n);
};

bool Solution::isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}
