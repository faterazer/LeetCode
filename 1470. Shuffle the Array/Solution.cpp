#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        for (int &x : nums)
            x <<= 10;
        for (int i = 0, j = n, k = 0; i < n; i++, j++, k += 2) {
            nums[k] |= nums[i] >> 10;
            nums[k + 1] |= nums[j] >> 10;
        }
        for (int &x : nums)
            x &= 0x3FF;
        return nums;
    }
};
