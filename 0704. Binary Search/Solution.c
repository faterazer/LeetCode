int search(int *nums, int numsSize, int target)
{
    int low = 0, high = numsSize - 1, mid;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (nums[mid] < target)
            low = mid + 1;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}
