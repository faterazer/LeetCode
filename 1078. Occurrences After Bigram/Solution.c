#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findOcurrences(char* text, char* first, char* second, int* returnSize)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
        if (text[i] == ' ')
            text[i] = '\0';
    int capacity = 128;
    char** res = (char**)malloc(sizeof(char*) * capacity);
    *returnSize = 0;
    char *word1 = "", *word2 = text;
    for (int i = 1; i < len; i++) {
        if (text[i - 1] == '\0') {
            if (strcmp(word1, first) == 0 && strcmp(word2, second) == 0)
                res[(*returnSize)++] = text + i;
            word1 = word2;
            word2 = text + i;
        }
    }
    return res;
}