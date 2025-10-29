#include <bit>
using namespace std;

class Solution {
public:
    int smallestNumber(int n)
    {
        return (1 << bit_width(static_cast<unsigned>(n))) - 1;
    }
};
