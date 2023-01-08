#include <string.h>

int prefixCount(char** words, int wordsSize, char* pref)
{
    int res = 0, len = strlen(pref);
    for (int i = 0; i < wordsSize; i++)
        if (strncmp(words[i], pref, len) == 0)
            ++res;
    return res;
}
