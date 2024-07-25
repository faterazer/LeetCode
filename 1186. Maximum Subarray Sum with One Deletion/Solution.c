#include <limits.h>
#include <math.h>

int maximumSum(int* arr, int arrSize)
{
    int res = arr[0], f0 = arr[0], f1 = 0;
    for (int i = 1; i < arrSize; i++) {
        f1 = fmax(f0, f1 + arr[i]);
        f0 = fmax(f0, 0) + arr[i];
        res = fmax(res, fmax(f0, f1));
    }
    return res;
}
