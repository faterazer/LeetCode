#include <math.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int *ret = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    *returnSize = 0;
    for (int i = 0, j = 0; i < nums1Size && j < nums2Size;) {
        if (nums1[i] < nums2[j])
            i++;
        else if (nums1[i] > nums2[j])
            j++;
        else {
            if (!(*returnSize) || ret[*(returnSize) - 1] != nums1[i])
                ret[(*returnSize)++] = nums1[i];
            i++;
            j++;
        }
    }
    ret = (int*)realloc(ret, *returnSize * sizeof(int));
    return ret;
}
