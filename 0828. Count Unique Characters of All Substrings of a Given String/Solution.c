#include <string.h>

int uniqueLetterString(char* s)
{
    int indices[26][2], res = 0, i = 0;
    memset(indices, -1, sizeof(int) * 52);
    for (i = 0; s[i]; ++i) {
        int idx = s[i] - 'A';
        res += (indices[idx][1] - indices[idx][0]) * (i - indices[idx][1]);
        indices[idx][0] = indices[idx][1];
        indices[idx][1] = i;
    }
    for (int j = 0; j < 26; ++j)
        res += (indices[j][1] - indices[j][0]) * (i - indices[j][1]);
    return res;
}
