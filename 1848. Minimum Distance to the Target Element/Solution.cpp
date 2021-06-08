#include <vector>
using namespace std;

class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        int res = INT_MAX, n = nums.size();
        for (int i = 0; i < n && res >= abs(i - start); i++)
            if (nums[i] == target)
                res = abs(i - start);
        return res;
    }
};
