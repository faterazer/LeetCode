#include <stdbool.h>

bool checkPossibility(int *nums, int numsSize)
{
    int cnt = 0;
    for (int i = 0; i < numsSize - 1 && cnt < 2; i++) {
        if (nums[i] > nums[i + 1]) {
            cnt += 1;
            if (i != 0 && i + 1 != numsSize - 1 && nums[i] > nums[i + 2] && nums[i - 1] > nums[i + 1])
                return false;
        }
    }
    return cnt < 2;
}
