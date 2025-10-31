#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums)
    {
        size_t n = nums.size(), i = n - 2;
        while (i < n) {
            if (nums[nums[i]] == nums[i])
                ++i;
            else
                swap(nums[i], nums[nums[i]]);
        }
        return { nums[n - 2], nums[n - 1] };
    }
};
