#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> res(nums.size());
        for (size_t i = 0; i < nums.size(); i++)
            res[i] = nums[nums[i]];
        return res;
    }
};
