int numIdenticalPairs(int *nums, int numsSize)
{
    int res = 0;
    int counter[101] = {0};
    for (int i = 0; i < numsSize; i++)
        res += counter[nums[i]]++;
    return res;
}
