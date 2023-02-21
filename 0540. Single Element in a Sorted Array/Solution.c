int singleNonDuplicate(int* nums, int numsSize)
{
    int lo = 0, hi = numsSize - 1;
    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (nums[mid] == nums[mid ^ 1])
            lo = mid + 1;
        else
            hi = mid;
    }
    return nums[lo];
}
