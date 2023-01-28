int waysToMakeFair(int* nums, int numsSize)
{
    int res = 0, s = 0;
    for (int i = 0; i < numsSize; i++)
        s += i & 1 ? -nums[i] : nums[i];
    for (int i = 0; i < numsSize; i++) {
        s += i & 1 ? nums[i] : -nums[i];
        res += s == 0;
        s += i & 1 ? nums[i] : -nums[i];
    }
    return res;
}
