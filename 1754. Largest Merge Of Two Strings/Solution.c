#include <stdlib.h>
#include <string.h>

char* largestMerge(char* word1, char* word2)
{
    int m = strlen(word1), n = strlen(word2);
    char* res = (char*)calloc(m + n + 1, sizeof(char));
    int i = 0, j = 0, tp = 0;
    while (i < m && j < n) {
        if (strcmp(word1 + i, word2 + j) > 0)
            res[tp++] = word1[i++];
        else
            res[tp++] = word2[j++];
    }
    if (i == m)
        strcat(res, word2 + j);
    else
        strcat(res, word1 + i);
    return res;
}
