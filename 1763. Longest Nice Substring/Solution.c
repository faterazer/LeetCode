#include <ctype.h>
#include <string.h>

void helper(char *s)
{
    unsigned upper = 0, lower = 0, unboth;
    for (int i = 0; s[i]; i++) {
        if (isupper(s[i]))
            upper |= 1 << (s[i] - 'A');
        else
            lower |= 1 << (s[i] - 'a');
    }
    unboth = upper ^ lower;
    for (int i = 0; s[i]; i++) {
        if ((unboth >> (tolower(s[i]) - 'a')) & 1) {
            s[i] = '\0';
            helper(s);
            helper(s + i + 1);
        }
    }
}

char* longestNiceSubstring(char *s)
{
    char *end = s + strlen(s);
    char *r = "";
    for ( helper(s); s < end; s += strlen(s) + 1) {
        if (strlen(s) > strlen(r))
            r = s;
    }
    return r;
}
