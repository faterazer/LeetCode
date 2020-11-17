#include <vector>
using namespace std;

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int index = 0, second = -1;  // index 是最大值的下标
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[index]) {
                second = nums[index];
                index = i;
            }
            else if (nums[i] > second)
                second = nums[i];
        }
        return second * 2 <= nums[index] ? index : -1;
    }
};
