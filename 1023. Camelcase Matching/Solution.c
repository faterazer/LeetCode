#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* camelMatch(char** queries, int queriesSize, char* pattern, int* returnSize)
{
    *returnSize = queriesSize;
    bool* res = (bool*)malloc(sizeof(bool) * queriesSize);
    int idx = 0;
    for (int k = 0; k < queriesSize; k++) {
        int i = 0, j = 0;
        for (; queries[k][i]; i++) {
            if (pattern[j] && queries[k][i] == pattern[j])
                j++;
            else if (isupper(queries[k][i]))
                break;
        }
        res[idx++] = !queries[k][i] && !pattern[j];
    }
    return res;
}
