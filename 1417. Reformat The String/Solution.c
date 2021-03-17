#include <ctype.h>
#include <math.h>
#include <stdlib.h>

char* reformat(char *s)
{
    int n1 = 0, n2 = 0, len = 0;     // n1 计数字母，n2计数数字
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i]))
            n1++;
        else
            n2++;
    }
    len = n1 + n2;
    char *res = (char*)malloc(sizeof(char) * (len + 1));
    res[0] = '\0';
    if (abs(n1 - n2) > 1)
        return res;
    if (n1 > n2) {
        n1 = 0;
        n2 = 1;
    }
    else {
        n1 = 1;
        n2 = 0;
    }
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i])) {
            res[n1] = s[i];
            n1 += 2;
        }
        else {
            res[n2] = s[i];
            n2 += 2;
        }
    }
    res[len] = '\0';
    return res;
}
