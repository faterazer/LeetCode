/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prevPermOpt1(int* arr, int arrSize, int* returnSize)
{
    *returnSize = arrSize;
    int i = arrSize - 1;
    while (i > 0 && arr[i] >= arr[i - 1])
        i--;
    if (i == 0)
        return arr;
    i -= 1;
    int j = arrSize - 1;
    while (arr[j] >= arr[i] || arr[j] == arr[j - 1])
        j--;
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    return arr;
}
