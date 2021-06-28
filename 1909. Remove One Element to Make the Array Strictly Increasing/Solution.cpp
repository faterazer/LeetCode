#include <vector>
using namespace std;

class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {
        int cnt = 0, n = nums.size();
        for (int i = 1; i < n && cnt < 2; i++) {
            if (nums[i] <= nums[i - 1]) {
                if (i - 2 >= 0 && nums[i] <= nums[i - 2])
                    nums[i] = nums[i - 1];
                cnt++;
            }
        }
        return cnt < 2;
    }
};
