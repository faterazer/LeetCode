#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

double trimMean_MK1(int *arr, int arrSize)
{
    double sum = 0.0;
    int seg = arrSize / 20, end = arrSize - seg;
    qsort(arr, arrSize, sizeof(int), cmp);
    for (int i = seg; i < end; i++)
        sum += arr[i];
    return sum / (arrSize * 0.9);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void kth_element(int *arr, int l, int k, int r)
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
        kth_element(arr, last + 1, k , r);
}

double trimMean_MK2(int *arr, int arrSize)
{
    double sum = 0.0;
    int seg = arrSize / 20, end = arrSize - seg;
    kth_element(arr, 0, seg, arrSize - 1);
    kth_element(arr, seg, arrSize - seg, arrSize - 1);
    for (int i = seg; i < end; i++)
        sum += arr[i];
    return sum / (arrSize * 0.9);
}
