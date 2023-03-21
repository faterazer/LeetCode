long long zeroFilledSubarray(int* nums, int numsSize)
{
    long long res = 0;
    for (int i = 0, j = 0; i < numsSize; i++) {
        if (nums[i] != 0)
            j = i + 1;
        res += i - j + 1;
    }
    return res;
}
