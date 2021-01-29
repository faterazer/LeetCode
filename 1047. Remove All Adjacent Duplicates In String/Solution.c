#include <string.h>

char* removeDuplicates(char *S)
{
    int last = 0, size = strlen(S);
    for (int i = 0; i < size; i++) {
        if (last > 0 && S[last - 1] == S[i])
            last--;
        else
            S[last++] = S[i];
    }
    S[last] = '\0';
    return S;
}
