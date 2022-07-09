#include <math.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void kth_element(int* arr, int l, int k, int r)
{
    if (l >= r || k < l || k > r)
        return;
    int last = l;
    for (int i = l + 1; i <= r; i++)
        if (arr[i] <= arr[l])
            swap(&arr[i], &arr[++last]);
    swap(&arr[l], &arr[last]);
    if (k < last)
        kth_element(arr, l, k, last - 1);
    else if (k > last)
        kth_element(arr, last + 1, k, r);
}

int minMoves2(int* nums, int numsSize)
{
    int mid_idx = numsSize / 2;
    kth_element(nums, 0, mid_idx, numsSize - 1);
    int mid = nums[mid_idx];

    int res = 0;
    for (int i = 0; i < numsSize; ++i)
        res += abs(nums[i] - mid);
    return res;
}
