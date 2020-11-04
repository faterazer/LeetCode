#include <stdbool.h>
#include <stdlib.h>

bool isSelfDividing(int n)
{
    int digit;
    for (int i = n; i; i /= 10) {
        digit = i % 10;
        if (!digit || n % digit)
            return false;
    }
    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int *returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * (right - left + 1));
    *returnSize = 0;
    for (int i = left; i <= right; i++)
        if (isSelfDividing(i))
            ret[(*returnSize)++] = i;
    ret = (int*)realloc(ret, sizeof(int) * *returnSize);
    return ret;
}
