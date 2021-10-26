#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    *returnSize = digitsSize;
    for (int i = digitsSize - 1; i >= 0 && ++digits[i] == 10; i--) {
        digits[i] = 0;
    }
    if (digits[0] == 0) {
        digits = (int*)realloc(digits, sizeof(int*) * (digitsSize + 1));
        (*returnSize)++;
        digits[0] = 1;
        digits[digitsSize] = 0;
    }
    return digits;
}
