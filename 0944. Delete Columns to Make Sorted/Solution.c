#include <string.h>

int minDeletionSize(char **A, int ASize)
{
    int res = 0, n = strlen(A[0]);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < ASize; j++) {
            if (A[j][i] < A[j - 1][i]) {
                res++;
                break;
            }
        }
    }
    return res;
}
