#include <stdlib.h>

char* baseNeg2(int n)
{
    char* res = (char*)calloc(32, sizeof(char));
    int idx = 0;
    while (n) {
        res[idx++] = '0' + (n & 1);
        n = -(n >> 1);
    }

    for (int i = 0, j = idx - 1; i < j; i++, j--) {
        char tmp = res[i];
        res[i] = res[j];
        res[j] = tmp;
    }

    if (!idx)
        res[idx++] = '0';
    return res;
}
