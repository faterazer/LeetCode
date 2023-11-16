#include <vector>
using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold)
    {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n;) {
            if (nums[i] & 1 || nums[i] > threshold) {
                ++i;
                continue;
            }
            int j = i + 1;
            while (j < n && nums[j] <= threshold && (nums[j] & 1) != (nums[j - 1] & 1))
                ++j;
            res = max(res, j - i);
            i = j;
        }
        return res;
    }
};
