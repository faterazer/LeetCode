#include <stdbool.h>

bool checkIfExist(int *arr, int arrSize)
{
    int hash[4001] = {0};
    for (int i = 0; i < arrSize; i++) {
        if (hash[arr[i] * 2 + 2000] || (arr[i] % 2 == 0 && hash[arr[i] / 2 + 2000]))
            return true;
        hash[arr[i] + 2000] = 1;
    }
    return false;
}
