#include <stdlib.h>

char dec2hex(int x)
{
    if (x < 10)
        return '0' + x;
    else
        return 'a' + x - 10;
}

char* toHex(int num)
{
    if (!num)
        return "0";
    unsigned n = num;
    char *res = (char*)calloc(9, sizeof(char));
    int len = 0;
    while (n) {
        res[len++] = dec2hex(n & 15);
        n >>= 4;
    }
    char tmp;
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        tmp = res[i];
        res[i] = res[j];
        res[j] = tmp;
    }
    return res;
}
