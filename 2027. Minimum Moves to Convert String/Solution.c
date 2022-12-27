#include <string.h>

int minimumMoves(char* s)
{
    int n = strlen(s), i = 0, res = 0;
    while (i < n) {
        if (s[i] == 'O')
            ++i;
        else {
            i += 3;
            ++res;
        }
    }
    return res;
}
