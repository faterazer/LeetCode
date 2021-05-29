#include <ctype.h>

int secondHighest(char *s)
{
    int digit = 0, cnt = 0;
    for (int i = 0; s[i]; i++)
        if (isdigit(s[i]))
            digit |= 1 << (s[i] - '0');
    for (int i = 9; i >= 0; i--)
        if (digit & (1 << i) && ++cnt == 2)
            return i;
    return -1;
}
