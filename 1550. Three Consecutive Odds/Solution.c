#include <stdbool.h>

bool threeConsecutiveOdds(int *arr, int arrSize)
{
    int cnt = 0;
    for (int i = 0; i < arrSize; i++) {
        cnt = arr[i] & 1 ? cnt + 1 : 0;
        if (cnt == 3)
            return true;
    }
    return false;
}
