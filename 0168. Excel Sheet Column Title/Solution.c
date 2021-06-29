#include <stdlib.h>

char* convertToTitle(int columnNumber)
{
    char *res = (char*)malloc(sizeof(char) * 8);
    int len = 0;
    while (columnNumber) {
        columnNumber--;
        res[len++] = 'A' + columnNumber % 26;
        columnNumber /= 26;
    }
    res[len] = '\0';
    char tmp;
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        tmp = res[i];
        res[i] = res[j];
        res[j] = tmp;
    }
    return res;
}
