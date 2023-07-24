#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
        for (size_t i = 1; i < nums.size(); i += 2) {
            if (nums[i] < nums[i - 1])
                swap(nums[i], nums[i - 1]);
            if (i + 1 < nums.size() && nums[i] < nums[i + 1])
                swap(nums[i], nums[i + 1]);
        }
    }
};
