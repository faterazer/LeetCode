int peakIndexInMountainArray(int *arr, int arrSize)
{
    int l = 0, r = arrSize - 1, mid;
    while (l < r) {
        mid = l + ((r - l) >> 1);
        if (arr[mid] < arr[mid + 1])
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
