#include <math.h>
#include <memory.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** commonChars(char **A, int ASize, int *returnSize)
{
    int hash[26] = {0};
    for (int i = 0; A[0][i]; i++)
        hash[A[0][i] - 'a']++;
    int hashbuff[26];
    for (int i = 0; i < ASize; i++) {
        char *s = A[i];
        memset(hashbuff, 0, sizeof(hashbuff));
        for (int j = 0; s[j]; j++)
            hashbuff[s[j] - 'a']++;
        for (int j = 0; j < 26; j++)
            hash[j] = fmin(hash[j], hashbuff[j]);
    }
    *returnSize = 0;
    for (int i = 0; i < 26; i++)
        *returnSize += hash[i];
    char** ret = (char**)malloc(sizeof(char*) * *returnSize);
    *returnSize = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < hash[i]; j++) {
            ret[*returnSize] = (char*)malloc(sizeof(char) * 2);
            ret[*returnSize][0] = 'a' + i;
            ret[(*returnSize)++][1] = '\0';
        }
    }
    return ret;
}
