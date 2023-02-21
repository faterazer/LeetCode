#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == nums[mid ^ 1])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};
