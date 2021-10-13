#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize)
{
    char **res = (char**)malloc(sizeof(char*) * n);
    *returnSize = n;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            res[i - 1] = "FizzBuzz";
        } else if (i % 3 == 0) {
            res[i - 1] = "Fizz";
        } else if (i % 5 == 0) {
            res[i - 1] = "Buzz";
        } else {
            res[i - 1] = (char*)calloc(10, sizeof(char));
            sprintf(res[i - 1], "%d", i);
        }
    }
    return res;
}
