#include <bitset>
#include <cstdint>
using namespace std;


class Solution {
public:
    uint32_t reverseBits_MK1(uint32_t n);
    uint32_t reverseBits_MK2(uint32_t n);
};

uint32_t Solution::reverseBits_MK1(uint32_t n)
{
    uint32_t res = 0;
    for (int i = 0; i < 32; i++)
        if (n & (1 << i))
            res |= 1 << (31 - i);
    return res;
}

uint32_t Solution::reverseBits_MK2(uint32_t n)
{
    bitset<32> b = n;
    for (int i = 0; i < 16; i++)
        if (b[i] != b[31 - i]) {
            b[i] = !b[i];
            b[31 - i] = !b[31 - i];
        }
    return b.to_ulong();
}
