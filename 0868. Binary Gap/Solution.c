#include <math.h>

int binaryGap(int n)
{
    int res = 0;
    for (int gap = -32; n; n >>= 1, gap++) {
        if (n & 1) {
            res = fmax(res, gap);
            gap = 0;
        }
    }
    return res;
}
