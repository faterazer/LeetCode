#include <string.h>

char* replaceDigits(char *s)
{
    int n = strlen(s);
    for (int i = 1; i < n; i += 2)
        s[i] += s[i - 1] - '0';
    return s;
}
