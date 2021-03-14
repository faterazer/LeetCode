#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return strlen(*(char**)b) - strlen(*(char**)a);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** stringMatching(char **words, int wordsSize, int *returnSize)
{
    qsort(words, wordsSize, sizeof(char*), cmp);
    char **res = (char**)malloc(sizeof(char*) * wordsSize);
    *returnSize = 0;
    for (int i = 1; i < wordsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (strstr(words[j], words[i])) {
                res[(*returnSize)++] = words[i];
                break;
            }
        }
    }
    res = realloc(res, *returnSize * sizeof(char*));
    return res;
}
