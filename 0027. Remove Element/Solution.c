// 双指针法
// Approach 1: Two Pointers
int removeElement_MK1(int *nums, int numsSize, int val)
{
    int last = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] != val)
            nums[last++] = nums[i];
    return last;
}

// 改进的双指针法，当要删除的元素很少时，速度更快
// Approach 2: Two Pointers - when elements to remove are rare
int removeElement_MK2(int *nums, int numsSize, int val)
{
    int tail = numsSize;
    for (int i = 0; i < tail; )
        if (nums[i] == val)
            nums[i] = nums[--tail];
        else
            i++;
    return tail;
}
