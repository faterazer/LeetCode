#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k)
    {
        ranges::sort(nums);
        int ans = 1, last = nums[0];
        for (int x : nums) {
            if (x - last > k) {
                ++ans;
                last = x;
            }
        }
        return ans;
    }
};
