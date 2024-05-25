#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference)
    {
        int max_idx = 0, min_idx = 0, n = nums.size();
        for (int j = indexDifference; j < n; j++) {
            int i = j - indexDifference;
            if (nums[i] > nums[max_idx])
                max_idx = i;
            else if (nums[i] < nums[min_idx])
                min_idx = i;
            if (nums[max_idx] - nums[j] >= valueDifference)
                return { max_idx, j };
            if (nums[j] - nums[min_idx] >= valueDifference)
                return { min_idx, j };
        }
        return { -1, -1 };
    }
};
