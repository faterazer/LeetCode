#include <ctype.h>
#include <stdlib.h>

char* reformatNumber(char *number)
{
    int cnt = 0, len = 0;
    for (int i = 0; number[i]; i++)
        if (isdigit(number[i]))
            cnt++;
    len = cnt + cnt / 3;
    if (cnt % 3)
        len++;
    char *res = (char*)malloc(sizeof(char) * len);
    len = 0;
    for (int i = 0; number[i]; i++) {
        if (!isdigit(number[i]))
            continue;
        if ((len + 1) % 4 == 0)
            res[len++] = '-';
        res[len++] = number[i];
    }
    if (cnt > 1 && cnt % 3 == 1) {
        char tmp = res[len - 3];
        res[len - 3] = res[len - 2];
        res[len - 2] = tmp;
    }
    res[len] = '\0';
    return res;
}
