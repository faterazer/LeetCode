#include <math.h>
#include <memory.h>

int findShortestSubArray(int *nums, int numsSize)
{
    int hash[50000][2];
    memset(hash, 0, sizeof(hash));
    int min_len = 1, max_deg = 0;
    for (int i = 0; i < numsSize; i++) {
        if (hash[nums[i]][0])
            hash[nums[i]][0]++;
        else {
            hash[nums[i]][0] = 1;
            hash[nums[i]][1] = i;
        }
        if (hash[nums[i]][0] > max_deg) {
            max_deg++;
            min_len = i - hash[nums[i]][1] + 1;
        }
        else if (hash[nums[i]][0] == max_deg)
            min_len = fmin(min_len, i - hash[nums[i]][1] + 1);
    }
    return min_len;
}
