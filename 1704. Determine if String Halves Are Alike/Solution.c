#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool halvesAreAlike(char *s)
{
    int cnt = 0, n = strlen(s), half = n / 2;
    char c;
    for (int i = 0; i < n; i++) {
        c = tolower(s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            cnt += i < half ? 1 : -1;
    }
    return cnt == 0;
}
