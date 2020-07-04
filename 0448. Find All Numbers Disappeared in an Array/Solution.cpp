#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums);
};

vector<int> Solution::findDisappearedNumbers(vector<int> &nums)
{
    for (size_t i = 0; i < nums.size(); i++)
        if (nums[abs(nums[i]) - 1] > 0)
            nums[abs(nums[i]) - 1] *= -1;
    vector<int> ret;
    for (size_t i = 0; i < nums.size(); i++)
        if (nums[i] > 0)
            ret.emplace_back(i + 1);
    return ret;
}
