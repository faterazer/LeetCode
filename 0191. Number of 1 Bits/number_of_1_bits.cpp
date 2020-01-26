#include <cstdint>
using namespace std;


class Solution {
public:
    int hammingWeight_MK1(uint32_t n);
    int hammingWeight_MK2(uint32_t n);
};

int Solution::hammingWeight_MK1(uint32_t n)
{
    int res = 0;
    for (int i = 0; i < 32; i++)
        if (n & (1 << i))
            res++;
    return res;
}

int Solution::hammingWeight_MK2(uint32_t n)
{
    int res = 0;
    while (n) {
        n &= n - 1;
        res++;
    }
    return res;
}
