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

void wiggleSort(int* nums, int numsSize)
{
    int mid_idx = numsSize / 2;
    kth_element(nums, 0, mid_idx, numsSize - 1);
    int mid = nums[mid_idx];

    #define A(x) nums[(2 * (x) + 1) % (numsSize | 1)]
    int i = 0, j = 0, k = numsSize - 1;
    while (j <= k) {
        if (A(j) > mid)
            swap(&A(j++), &A(i++));
        else if (A(j) < mid)
            swap(&A(j), &A(k--));
        else
            ++j;
    }
}
