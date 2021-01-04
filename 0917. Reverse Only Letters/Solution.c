#include <ctype.h>
#include <string.h>

char* reverseOnlyLetters(char *S)
{
    int l = 0, r = strlen(S) - 1;
    while (l < r) {
        while (l < r && !isalpha(S[l]))
            l++;
        while (r > l && !isalpha(S[r]))
            r--;
        if (l < r) {
            char tmp = S[l];
            S[l++] = S[r];
            S[r--] = tmp;
        }
    }
    return S;
}
