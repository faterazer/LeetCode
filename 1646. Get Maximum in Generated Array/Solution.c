#include <math.h>

int getMaximumGenerated(int n)
{
    if (n < 2)
        return n;
    int arr[n + 1], max = 1;
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = i % 2 == 0 ? arr[i / 2] : arr[i / 2] + arr[i / 2 + 1];
        max = fmax(arr[i], max);
    }
    return max;
}
