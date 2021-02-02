#include <stdint.h>

int hammingWeight(uint32_t n)
{
    int res = 0;
    for (; n; n &= n - 1)
        res++;
    return res;
}
