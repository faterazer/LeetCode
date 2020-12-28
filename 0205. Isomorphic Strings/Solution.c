#include <stdbool.h>

bool isIsomorphic(char *s, char *t)
{
    int hash_s[128] = {0}, hash_t[128] = {0};
    for (int i = 0; s[i]; i++) {
        int si = s[i], ti = t[i];
        if (hash_s[si] != hash_t[ti])
            return false;
        else
            hash_s[si] = hash_t[ti] = i + 1;
    }
    return true;
}
