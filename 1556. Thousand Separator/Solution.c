#include <stdlib.h>

char* thousandSeparator(int n)
{
    char *res = (char*)malloc(sizeof(char) * 32), temp;
    int cnt = 0, len = 0;
    do {
        if (++cnt == 4) {
            res[len++] = '.';
            cnt = 1;
        }
        res[len++] = n % 10 + '0';
        n /= 10;
    } while (n);
    res[len] = '\0';
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        temp = res[i];
        res[i] = res[j];
        res[j] = temp;
    }
    return res;
}
