#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums)
    {
        ranges::sort(nums);
        for (size_t i = 0; i < nums.size(); i += 2)
            swap(nums[i], nums[i + 1]);
        return nums;
    }
};
