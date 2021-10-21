#include <string.h>

int countSegments(char* s)
{
    int res = 0, n = strlen(s) + 1;
    for (int i = 1; i < n; i++) {
        if ((s[i] == ' ' || s[i] == '\0') && s[i - 1] != ' ')
            res++;
    }
    return res;
}
