#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums)
    {
        vector<int> premax(nums.size());
        premax[0] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i)
            premax[i] = max(premax[i - 1], nums[i]);
            
        int sufmin = INT_MAX;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (premax[i] > sufmin)
                premax[i] = premax[i + 1];
            sufmin = min(sufmin, nums[i]);
        }
        return premax;
    }
};
