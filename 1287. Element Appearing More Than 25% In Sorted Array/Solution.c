int lower_bound(int *arr, int arrSize, int x)
{
    int l = 0, r = arrSize, m;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (arr[m] < x)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int upper_bound(int *arr, int arrSize, int x)
{
    int l = 0, r = arrSize, m;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (arr[m] > x)
            r = m;
        else
            l = m + 1;
    }
    return r;
}

int findSpecialInteger(int *arr, int arrSize)
{
    int gap = arrSize / 4;
    for (int i = gap; i < arrSize; i += gap)
        if (upper_bound(arr, arrSize, arr[i]) - lower_bound(arr, arrSize, arr[i]) > gap)
            return arr[i];
    return 0;
}
