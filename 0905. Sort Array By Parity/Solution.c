/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArrayByParity(int *A, int ASize, int *returnSize)
{
    *returnSize = ASize;
    int j = 0;
    for (int i = 0; i < ASize; i++) {
        if (A[i] % 2 == 0) {
            int tmp = A[j];
            A[j++] = A[i];
            A[i] = tmp;
        }
    }
    return A;
}
