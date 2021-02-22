int findNumbers(int *nums, int numsSize)
{
    int res = 0;
    for (int i = 0; i < numsSize; i++)
        if ((nums[i] > 9 && nums[i] < 100) || (nums[i] > 999 && nums[i] < 10000) || nums[i] > 99999)
            res++;
    return res;
}
