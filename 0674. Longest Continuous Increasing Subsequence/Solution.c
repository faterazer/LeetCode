#define max(a, b) ((a > b) ? (a) : (b))

int findLengthOfLCIS(int *nums, int numsSize)
{
    if (!numsSize)
        return 0;
    int maxLen = 1, curLen = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1])
            curLen += 1;
        else {
            maxLen = max(maxLen, curLen);
            curLen = 1;
        }
    }
    return max(maxLen, curLen);
}
