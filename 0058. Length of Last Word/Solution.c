#include <string.h>

int lengthOfLastWord(char *s)
{
    int i = strlen(s) - 1, res = 0;
    while (i >= 0 && s[i] == ' ')
        i--;
    while (i >= 0 && s[i] != ' ') {
        res++;
        i--;
    }
    return res;
}
