#include <stdlib.h>

int lower_bound(int *arr, int left, int right, int x)
{
    int l = left, r = right, m;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (arr[m] < x)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int findTheDistanceValue(int *arr1, int arr1Size, int *arr2, int arr2Size, int d)
{
    qsort(arr2, arr2Size, sizeof(int), cmp);
    int res = 0;
    for (int i = 0; i < arr1Size; i++) {
        int j = lower_bound(arr2, 0, arr2Size - 1, arr1[i]);
        if (j < arr2Size && abs(arr1[i] - arr2[j]) <= d || j > 0 && abs(arr1[i] - arr2[j - 1]) <= d)
            continue;
        res++;
    }
    return res;
}
