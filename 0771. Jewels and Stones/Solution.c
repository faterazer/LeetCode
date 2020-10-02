#include <ctype.h>

int numJewelsInStones(char *J, char *S)
{
    char hash[52] = { 0 };
    for (int i = 0; J[i]; i++) {
        if (isupper(J[i]))
            hash[J[i] - 'A' + 26] = 1;
        else
            hash[J[i] - 'a'] = 1;
    }
    int cnt = 0;
    for (int i = 0; S[i]; i++)
        if ((isupper(S[i]) && hash[S[i] - 'A' + 26]) || (islower(S[i]) && hash[S[i] - 'a']))
            cnt += 1;
    return cnt;
}
