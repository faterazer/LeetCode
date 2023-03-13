#include <string.h>

int countTriplets(int* nums, int numsSize)
{
    int cnt[1 << 16];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < numsSize; i++)
        for (int j = 0; j < numsSize; j++)
            ++cnt[nums[i] & nums[j]];

    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i] ^ 0xFFFF;
        for (int j = x; j; j = (j - 1) & x)
            res += cnt[j];
        res += cnt[0];
    }
    return res;
}
