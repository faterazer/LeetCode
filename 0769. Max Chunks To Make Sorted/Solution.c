#include <math.h>

int maxChunksToSorted(int* arr, int arrSize)
{
    int res = 0, max = 0;
    for (int i = 0; i < arrSize; i++) {
        max = fmax(max, arr[i]);
        if (max == i)
            ++res;
    }
    return res;
}
