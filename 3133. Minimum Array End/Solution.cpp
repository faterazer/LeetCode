#include <bit>
#include <ranges>
#include <string>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x)
    {
        long long res = x, t = ~x;
        for (--n; n; n >>= 1) {
            long long low_bit = t & -t;
            res |= (n & 1) * low_bit;
            t ^= low_bit;
        }
        return res;
    }
};
