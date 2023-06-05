#include <vector>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums)
    {
        for (size_t i = 0, j = 0; i < nums.size(); i++) {
            if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            if (nums[i])
                swap(nums[i], nums[j++]);
        }
        return nums;
    }
};
