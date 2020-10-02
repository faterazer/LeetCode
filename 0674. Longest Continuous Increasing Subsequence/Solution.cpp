#include <vector>
using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int maxLen = 1, curLen = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                curLen += 1;
            else {
                maxLen = max(maxLen, curLen);
                curLen = 1;
            }
        }
        return max(maxLen, curLen);
    }
};
