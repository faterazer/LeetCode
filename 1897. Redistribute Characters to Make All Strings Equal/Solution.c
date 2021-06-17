#include <stdbool.h>

bool makeEqual(char **words, int wordsSize)
{
    int cnt[26] = {0};
    for (int i = 0; i < wordsSize; i++)
        for (int j = 0; words[i][j]; j++)
            cnt[words[i][j] - 'a']++;
    for (int i = 0; i < 26; i++)
        if (cnt[i] % wordsSize != 0)
            return false;
    return true;
}
