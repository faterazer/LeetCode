#include <vector>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums)
    {
        int dp1 = 0, dp2 = 0, dp3 = 0;
        int size = nums.size(), i = 0;
        while (i < size) {
            int beg = i;
            while (i < size && nums[i] == nums[beg])
                ++i;
            int cnt = i - beg;

            if (beg > 0 && nums[beg] != nums[beg - 1] + 1) {
                if (dp1 + dp2 > 0)
                    return false;
                else {
                    dp1 = cnt;
                    dp2 = dp3 = 0;
                }
            } else {
                if (dp1 + dp2 > cnt)
                    return false;
                int remain = cnt - dp1 - dp2;
                int tmp = min(dp3, remain);
                dp3 = tmp + dp2;
                dp2 = dp1;
                dp1 = remain - tmp;
            }
        }
        return dp1 == 0 && dp2 == 0;
    }
};
