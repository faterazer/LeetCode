#include <stdlib.h>
#include <string.h>

char* largestOddNumber(char *num)
{
    for (int i = strlen(num) - 1; i >= 0; i--) {
        if ((num[i] - '0') % 2) {
            char *res;
            res = (char*)malloc(sizeof(char) * (i + 2));
            strncpy(res, num, i + 1);
            res[i + 1] = '\0';
            return res;
        }
    }
    return "";
}
