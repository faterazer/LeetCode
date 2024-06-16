#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n)
    {
        int res = 0;
        size_t max_right = 0, i = 0;
        while (max_right < n) {
            if (i < nums.size() && nums[i] <= max_right + 1)
                max_right += nums[i++];
            else {
                res++;
                max_right = 2 * max_right + 1;
            }
        }
        return res;
    }
};
