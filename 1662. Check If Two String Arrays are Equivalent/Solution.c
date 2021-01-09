#include <stdbool.h>
#include <string.h>

bool arrayStringsAreEqual(char **word1, int word1Size, char **word2, int word2Size)
{
    int i = 0, j = 0, k = 0, l = 0;
    while (i < word1Size && j < word2Size) {
        if (word1[i][k] != word2[j][l])
            return false;
        k++;
        l++;
        if (k == strlen(word1[i])) {
            k = 0;
            i++;
        }
        if (l == strlen(word2[j])) {
            l = 0;
            j++;
        }
    }
    return i == word1Size && j == word2Size;
}
