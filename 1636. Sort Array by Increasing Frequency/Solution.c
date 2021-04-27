#include <memory.h>
#include <stdlib.h>

int counter[201] = {0};

int cmp(const void *a, const void *b)
{
    int aa = *(int*)a, bb = *(int*)b;
    if (counter[aa + 100] != counter[bb + 100])
        return counter[aa + 100] - counter[bb + 100];
    return -(aa - bb);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* frequencySort(int *nums, int numsSize, int *returnSize)
{
    memset(counter, 0, sizeof(counter));
    for (int i = 0; i < numsSize; i++)
        counter[nums[i] + 100]++;
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = numsSize;
    return nums;
}
