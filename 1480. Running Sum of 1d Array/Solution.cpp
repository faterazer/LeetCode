#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> runningSum_MK1(vector<int> &nums)
    {
        for (size_t i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        return nums;
    }

    vector<int> runningSum_MK2(vector<int> &nums)
    {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        return nums;
    }
};
