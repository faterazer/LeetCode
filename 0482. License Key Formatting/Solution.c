#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* licenseKeyFormatting(char* s, int k)
{
    int len = strlen(s), size = 0;
    char *res = (char*)calloc(len + len / k + 1, sizeof(char));
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] != '-') {
            if ((size + 1) % (k + 1) == 0)
                res[size++] = '-';
            res[size++] = toupper(s[i]);
        }
    }
    char tmp;
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        tmp = res[i];
        res[i] = res[j];
        res[j] = tmp;
    }
    return res;
}
