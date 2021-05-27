#include <stdbool.h>
#include <string.h>

bool checkOnesSegment(char *s)
{
    int cnt = 0, n = strlen(s);
    for (int i = 1; i < n; i++)
        if (s[i] ^ s[i - 1] && ++cnt > 1)
            return false;
    return true;
}
