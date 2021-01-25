#include <stdlib.h>
#include <string.h>

char* removeOuterParentheses(char *S)
{
    size_t size = strlen(S);
    char *res = (char*)malloc(sizeof(char) * (size + 1));
    int left = 0, idx = 0;
    for (size_t i = 0; i < size; i++)
        if ((S[i] == '(' && left++ > 0) || (S[i] == ')' && left-- > 1))
            res[idx++] = S[i];
    res[idx++] = '\0';
    res = (char*)realloc(res, sizeof(char) * idx);
    return res;
}
