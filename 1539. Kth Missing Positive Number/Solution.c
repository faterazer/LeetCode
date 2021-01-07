int findKthPositive(int *arr, int arrSize, int k)
{
    int l = 0, r = arrSize, m;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (arr[m] - m - 1 < k)
            l = m + 1;
        else
            r = m;
    }
    return l + k;
}
