bool validMountainArray(int *A, int ASize)
{
    int i = 0, j = ASize - 1;
    while (i < j && A[i] < A[i + 1])
        i++;
    while (i < j && A[j] < A[j - 1])
        j--;
    return i > 0 && j < ASize - 1 && i == j;
}
