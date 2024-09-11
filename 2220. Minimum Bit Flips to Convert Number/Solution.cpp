#include <bit>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal)
    {
        return popcount(static_cast<unsigned>(start ^ goal));
    }
};
