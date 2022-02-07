int majorityElement(int* nums, int numsSize)
{
    int majority, count = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (!count)
            majority = nums[i];
        count += majority == nums[i] ? 1 : -1;
    }
    return majority;
}
