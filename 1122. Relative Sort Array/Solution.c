/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size, int *returnSize)
{
    int hash[1001] = {0};
    for (int i = 0; i < arr1Size; i++)
        hash[arr1[i]]++;
    *returnSize = 0;
    for (int i = 0; i < arr2Size; i++)
        for (int *j = &hash[arr2[i]]; *j; (*j)--)
            arr1[(*returnSize)++] = arr2[i];
    for (int i = 0; i < 1001; i++)
        for (int j = hash[i]; j; j--)
            arr1[(*returnSize)++] = i;
    return arr1;
}
