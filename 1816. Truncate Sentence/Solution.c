#include <stdlib.h>
#include <string.h>

char* truncateSentence(char *s, int k)
{
    char *res;
    int i;
    for (i = 0; s[i]; i++)
        if (s[i] == ' ' && --k == 0)
            break;
    res = (char*)malloc(sizeof(char) * (i + 1));
    strncpy(res, s, i);
    res[i] = '\0';
    return res;
}
