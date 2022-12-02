#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char* boxes, int* returnSize)
{
    int lcnt = 0, rcnt = 0, state = 0, n;
    for (n = 0; boxes[n]; n++) {
        if (boxes[n] == '1') {
            state += n;
            ++rcnt;
        }
    }

    *returnSize = n;
    int* res = (int*)malloc(sizeof(int) * n);
    for (size_t i = 0; i < n; i++) {
        res[i] = state;
        if (boxes[i] == '1') {
            ++lcnt;
            --rcnt;
        }
        state = state + lcnt - rcnt;
    }
    return res;
}
