int arithmeticTriplets(int* nums, int numsSize, int diff)
{
    int res = 0, i = 0, j = 0;
    for (int k = 0; k < numsSize; k++) {
        while (nums[j] + diff < nums[k])
            j++;
        if (nums[j] + diff > nums[k])
            continue;
        while (nums[i] + 2 * diff < nums[k])
            i++;
        if (nums[i] + 2 * diff == nums[k])
            res++;
    }
    return res;
}
