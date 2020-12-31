#include <stdbool.h>

bool isMonotonic_MK1(int *A, int ASize)
{
    int sign = 0;
    for (int i = 1; i < ASize; i++) {
        if (A[i] != A[i - 1]) {
            if (sign && (sign > 0) != (A[i] > A[i - 1]))
                return false;
            sign = A[i] - A[i - 1];
        }
    }
    return true;
}

bool isMonotonic_MK2(int *A, int ASize)
{
    bool increasing = true, decreasing = true;
    for (int i = 1; i < ASize; i++) {
        if (A[i] > A[i - 1])
            decreasing = false;
        else if (A[i] < A[i - 1])
            increasing = false;
    }
    return increasing || decreasing;
}
