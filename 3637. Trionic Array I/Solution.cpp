#include <vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums)
    {
        if (nums[1] <= nums[0])
            return false;
        int cnt = 0;
        for (size_t i = 2; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1])
                return false;
            if (nums[i] > nums[i - 1] != nums[i - 1] > nums[i - 2])
                ++cnt;
            if (cnt > 2)
                return false;
        }
        return cnt == 2;
    }
};
