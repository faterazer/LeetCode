int searchInsert(int* nums, int numsSize, int target)
{
    int l = 0, r = numsSize - 1, m;
    while (l <= r) {
        m = l + ((r - l) >> 1);
        if (nums[m] < target)
            l = m + 1;
        else if (nums[m] > target)
            r = m - 1;
        else
            return m;
    }
    return l;
}
