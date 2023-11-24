#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int res = 0, left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                res += right - left;
                left++;
            } else
                right--;
        }
        return res;
    }
};
