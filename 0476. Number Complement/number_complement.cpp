#include <cmath>

class Solution
{
public:
    int findComplement_MK1(int num);
    int findComplement_MK2(int num);
};

int Solution::findComplement_MK1(int num)
{
    int mask = 1;
    while (mask < num)
        mask = (mask << 1) + 1;
    return num ^ mask;
}

int Solution::findComplement_MK2(int num)
{
    unsigned mask = ~0;
    while (num & mask)
        mask <<= 1;
    return num ^ ~mask;
}
