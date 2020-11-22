#include <stdbool.h>
#include <string.h>

bool isAnagram(char *s, char *t)
{
    if (strlen(s) != strlen(t))
        return false;
    int hash[26] = {0};
    for (int i = 0; s[i]; i++)
        hash[s[i] - 'a']++;
    for (int i = 0; t[i]; i++) {
        if (!hash[t[i] -'a'])
            return false;
        hash[t[i] - 'a']--;
    }
    return true;
}
