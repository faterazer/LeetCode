#include <stdlib.h>

int cmp1(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int cmp2(const void* a, const void* b)
{
    int *aa = (int*)a, *bb = (int*)b;
    return aa[0] - bb[0];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* advantageCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int n = nums1Size;
    int tmp[n][2];
    for (int i = 0; i < n; i++) {
        tmp[i][0] = nums2[i];
        tmp[i][1] = i;
    }
    qsort(nums1, n, sizeof(int), cmp1);
    qsort(tmp, n, sizeof(tmp[0]), cmp2);
    int* res = (int*)malloc(sizeof(int) * n);
    int lo = 0, hi = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (nums1[hi] > tmp[i][0])
            res[tmp[i][1]] = nums1[hi--];
        else
            res[tmp[i][1]] = nums1[lo++];
    }
    *returnSize = n;
    return res;
}
