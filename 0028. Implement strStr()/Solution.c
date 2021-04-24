#include <string.h>

int strStr_MK1(char *haystack, char *needle)
{
    char *s = strstr(haystack, needle);
    return s ? s - haystack : -1;
}

int strStr_MK2(char *haystack, char *needle)
{
    if (!(*needle))
        return 0;
    int i, j;
    for (i = 0; haystack[i]; i++) {
        for (j = 0; haystack[i + j] && needle[j] && haystack[i + j] == needle[j]; j++)
            ;
        if (!needle[j])
            return i;
        if (!haystack[i + j])
            return -1;
    }
    return -1;
}

int strStr_MK3(char *haystack, char *needle)
{
    if (*needle == '\0')
        return 0;
    int n = strlen(needle);
    int next[n];
    next[0] = 0;
    for (int i = 1, j = 0; needle[i]; i++) {
        while (j > 0 && needle[i] != needle[j])
            j = next[j - 1];
        if (needle[i] == needle[j])
            j++;
        next[i] = j;
    }
    for (int i = 0, j = 0; haystack[i]; i++) {
        while (j > 0 && haystack[i] != needle[j])
            j = next[j - 1];
        if (haystack[i] == needle[j])
            j++;
        if (!needle[j])
            return i - j + 1;
    }
    return -1;
}
