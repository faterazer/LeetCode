#include <stdlib.h>

char* generateTheString(int n)
{
    char *s = (char*)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++)
        s[i] = 'a';
    s[n] = '\0';
    if (n % 2 == 0)
        s[n - 1] = 'b';
    return s;
}
