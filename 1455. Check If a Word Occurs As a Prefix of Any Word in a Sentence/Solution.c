#include <stdbool.h>
#include <string.h>

bool isPrefix(char *s1, char *s2)
{
    for (int i = 0; s2[i]; i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}

int isPrefixOfWord(char *sentence, char *searchWord)
{
    if (isPrefix(sentence, searchWord))
        return 1;
    int i = 2;
    for (char *p = strchr(sentence, ' '); p; p = strchr(p + 1, ' '), i++)
        if (isPrefix(p + 1, searchWord))
            return i;
    return -1;
}
