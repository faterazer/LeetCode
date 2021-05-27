#include <bitset>
using namespace std;

class Solution
{
public:
    int hammingDistance_MK1(int x, int y)
    {
        int dis = 0;
        for (x ^= y; x; x &= (x - 1))
            dis++;
        return dis;
    }

    int hammingDistance_MK2(int x, int y)
    {
        return bitset<32>(x ^ y).count();
    }
};
