#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes_MK1(vector<int> &nums); // 0 少时更快
    void moveZeroes_MK2(vector<int> &nums); // 0 多时更快
};

void Solution::moveZeroes_MK1(vector<int> &nums)
{
    size_t last = 0;
    for (size_t i = 0; i < nums.size(); i++)
        if (nums[i])
            nums[last++] = nums[i];
    while (last < nums.size())
        nums[last++] = 0;
}

void Solution::moveZeroes_MK2(vector<int> &nums)
{
    for (size_t curr = 0, last = 0; curr < nums.size(); curr++)
        if (nums[curr])
            swap(nums[last++], nums[curr]);
}
