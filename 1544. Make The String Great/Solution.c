#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* makeGood(char *s)
{
    int n = strlen(s), len = 0;
    char *res = (char*)malloc(sizeof(char) * (n + 1));
    for ( ; *s; s++) {
        if (len && tolower(res[len - 1]) == tolower(*s) && res[len - 1] != *s)
            len--;
        else
            res[len++] = *s;
    }
    res[len] = '\0';
    return res;
}
