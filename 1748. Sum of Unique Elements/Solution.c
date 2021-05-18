int sumOfUnique(int *nums, int numsSize)
{
    int res = 0;
    int count[101] = {0};
    for (int i = 0; i < numsSize; i++)
        count[nums[i]]++;
    for (int i = 1; i <= 100; i++)
        if (count[i] == 1)
            res += i;
    return res;
}
