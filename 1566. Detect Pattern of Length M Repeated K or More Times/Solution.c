#include <stdbool.h>

bool containsPattern(int *arr, int arrSize, int m, int k)
{
    int goal = (k - 1) * m, cnt = 0;
    for (int i = 0; i + m < arrSize; i++) {
        if (arr[i] == arr[i + m]) {
            if (++cnt == goal)
                return true;
        }
        else
            cnt = 0;
    }
    return false;
}
