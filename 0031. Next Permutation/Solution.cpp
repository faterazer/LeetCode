#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int idx = nums.size() - 1;
        while (idx > 0 && nums[idx] <= nums[idx - 1])
            idx--;

        if (idx == 0) {
            ranges::reverse(nums);
            return;
        }

        int j = nums.size() - 1;
        while (nums[j] <= nums[idx - 1])
            j--;
        swap(nums[idx - 1], nums[j]);
        reverse(nums.begin() + idx, nums.end());
    }
};
