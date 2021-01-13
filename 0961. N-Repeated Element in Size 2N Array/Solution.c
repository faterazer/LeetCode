int repeatedNTimes(int *A, int ASize)
{
    for (int i = 2; i < ASize; i++)
        if (A[i] == A[i - 1] || A[i] == A[i - 2])
            return A[i];
    return A[0];
}
