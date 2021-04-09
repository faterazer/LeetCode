#include <math.h>

int countGoodTriplets(int *arr, int arrSize, int a, int b, int c)
{
    int res = 0;
    int preSum[1001] = {0};
    for (int j = 0; j < arrSize; j++) {
        for (int k = j + 1; k < arrSize; k++) {
            if (abs(arr[j] - arr[k]) > b)
                continue;
            int l = fmax(0, fmax(arr[j] - a, arr[k] - c));
            int r = fmin(1000, fmin(arr[j] + b, arr[j] + c));
            if (l <= r) {
                res += preSum[r];
                if (l)
                    res -= preSum[l];
            }
        }
        for (int k = arr[j]; k <= 1000; k++)
            preSum[k]++;
    }
    return res;
}
