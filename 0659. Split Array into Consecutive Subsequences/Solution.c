#include <math.h>
#include <stdbool.h>

bool isPossible(int* nums, int numsSize)
{
    int dp1 = 0, dp2 = 0, dp3 = 0;
    int i = 0;
    while (i < numsSize) {
        int beg = i++;
        while (i < numsSize && nums[i] == nums[beg])
            ++i;
        int cnt = i - beg;

        if (beg > 0 && nums[beg] != nums[beg - 1] + 1) {
            if (dp1 + dp2 > 0)
                return false;
            dp1 = cnt;
            dp2 = dp3 = 0;
        } else {
            if (dp1 + dp2 > cnt)
                return false;
            int remain = cnt - dp1 - dp2;
            int tmp = fmin(dp3, remain);
            dp3 = tmp + dp2;
            dp2 = dp1;
            dp1 = remain - tmp;
        }
    }
    return dp1 == 0 && dp2 == 0;
}
