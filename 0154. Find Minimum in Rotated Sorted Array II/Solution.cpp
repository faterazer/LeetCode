#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1, m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (m > 0 && nums[m] < nums[m - 1])
                return nums[m];
            if (nums[m] < nums[r])
                r = m;
            else if (nums[m] > nums[r])
                l = m + 1;
            else
                r -= 1;
        }
        return nums[r];
    }
};
