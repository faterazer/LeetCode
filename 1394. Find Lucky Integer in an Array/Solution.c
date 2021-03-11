#include <math.h>

int findLucky(int *arr, int arrSize)
{
    int hash[501] = {0};
    for (int i = 0; i < arrSize; i++)
        hash[arr[i]]++;
    for (int i = 500; i > 0; i--)
        if (hash[i] == i)
            return i;
    return -1;
}
