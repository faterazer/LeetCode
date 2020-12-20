#include <algorithm>
using namespace std;

class Solution
{
public:
    int binaryGap(int n)
    {
        int res = 0;
        for (int gap = -32; n; n >>= 1, gap++) {
            if (n & 1) {
                res = max(res, gap);
                gap = 0;
            }
        }
        return res;
    }
};
