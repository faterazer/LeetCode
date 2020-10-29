#include <vector>
using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int ones = 0;
        for (auto it = bits.rbegin() + 1; it != bits.rend() && *it == 1; it++)
            ones++;
        return ones % 2 == 0;
    }
};
