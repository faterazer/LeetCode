#include <stdlib.h>
#include <string.h>

char* sortString(char *s)
{
    int map[26] = {0};
    for (int i = 0; s[i]; i++)
        map[s[i] - 'a']++;
    
    int n = strlen(s), idx = 0;
    char *res = (char*)malloc(sizeof(char) * (n + 1));
    while (idx < n) {
        for (int i = 0; i < 26; i++)
            if (map[i]-- > 0)
                res[idx++] = 'a' + i;
        for (int i = 25; i >= 0; i--)
            if (map[i]-- > 0)
                res[idx++] = 'a' + i;
    }
    res[idx] = '\0';
    return res;
}
