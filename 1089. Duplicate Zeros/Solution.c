void duplicateZeros(int *arr, int arrSize)
{
    int zeros = 0;
    for (int i = 0; i < arrSize; i++)
        zeros += arr[i] == 0;
    for (int i = arrSize - 1; i >= 0 && zeros; i--) {
        if (i + zeros < arrSize)
            arr[i + zeros] = arr[i];
        if (!arr[i] && i + (--zeros) < arrSize)
            arr[i + zeros] = arr[i];
    }
}
