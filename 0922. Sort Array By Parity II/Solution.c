/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int *A, int ASize, int *returnSize)
{
    *returnSize = ASize;
    for (int i = 0, j = 1; i < ASize; i += 2) {
        if (A[i] & 1) {
            while (A[j] & 1)
                j += 2;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    return A;
}
