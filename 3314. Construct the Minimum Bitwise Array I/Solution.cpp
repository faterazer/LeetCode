#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums)
    {
        for (int& x : nums) {
            if ((x & 1) == 0)
                x = -1;
            else
                x ^= ((x + 1) & ~x) >> 1;
        }
        return nums;
    }
};
