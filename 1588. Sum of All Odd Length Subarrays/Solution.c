int sumOddLengthSubarrays(int *arr, int arrSize)
{
    int res = 0;
    for (int i = 0; i < arrSize; i++)
        res += ((i + 1) * (arrSize - i) + 1) / 2 * arr[i];
    return res;
}
