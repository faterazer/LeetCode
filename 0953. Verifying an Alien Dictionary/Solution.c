#include <stdbool.h>

int wordCmp(char *s1, char *s2, int dict[])
{
    while (*s1 == *s2) {
        if (*s1 == '\0')
            return 0;
        s1++;
        s2++;
    }
    return dict[*s1 - 'a'] - dict[*s2 - 'a'];
}

bool isAlienSorted(char **words, int wordsSize, char *order)
{
    int dict[26];
    for (int i = 0; order[i]; i++)
        dict[order[i] - 'a'] = i + 1;
    for (int i = 1; i < wordsSize; i++)
        if (wordCmp(words[i - 1], words[i], dict) > 0)
            return false;
    return true;
}
