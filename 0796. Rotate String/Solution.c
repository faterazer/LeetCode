#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool rotateString(char *A, char *B)
{
    char *s = (char*)malloc(sizeof(char) * (strlen(A) * 2 + 1));
    memset(s, 0, sizeof(char) * (strlen(A) * 2 + 1));
    strcat(strcat(s, A), A);
    bool ret = strstr(s, B);
    free(s);
    return strlen(A) == strlen(B) && ret;
}
