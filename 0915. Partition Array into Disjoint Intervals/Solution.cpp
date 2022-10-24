#include <vector>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums)
    {
        int n = nums.size(), res = 1, last_max = nums[0], cur_max = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < last_max) {
                res = i + 1;
                last_max = cur_max;
            } else
                cur_max = max(cur_max, nums[i]);
        }
        return res;
    }
};
