#include <ctype.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize)
{
    int map[26] = { 1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2 };
    char** res = (char**)malloc(sizeof(char*) * wordsSize);
    int len = 0;
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        res[len++] = word;
        for (int j = 1; word[j]; j++) {
            if (map[tolower(word[j]) - 'a'] != map[tolower(word[j - 1]) - 'a']) {
                len--;
                break;
            }
        }
    }
    *returnSize = len;
    return res;
}
