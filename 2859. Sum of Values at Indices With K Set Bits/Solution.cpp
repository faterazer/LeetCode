#include <bit>
#include <vector>
using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k)
    {
        int res = 0;
        for (size_t i = 0; i < nums.size(); i++)
            if (popcount(i) == k)
                res += nums[i];
        return res;
    }
};
