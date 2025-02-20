#include <bit>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n)
    {
        const unsigned MASK = 0x55555555;
        return { popcount(n & MASK), popcount(n & ~MASK) };
    }
};
