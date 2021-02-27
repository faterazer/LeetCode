#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getNoZeroIntegers(int n, int *returnSize)
{
    int *res = (int*)malloc(sizeof(int) * 2);
    res[0] = res[1] = 0;
    *returnSize = 2;
    int power = 1, digit;
    for (; n; n /= 10, power *= 10) {
        if (n % 10 > 2 || n < 10)
            digit = n % 10;
        else {
            digit = 10 + n % 10;
            n -= 10;
        }
        res[0] += digit / 2 * power;
        res[1] += (digit + 1) / 2 * power;
    }
    return res;
}
