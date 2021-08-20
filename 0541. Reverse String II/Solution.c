#include <math.h>
#include <string.h>

void reverse(char *s, int left, int right)
{
    char tmp;
    while (left < right) {
        tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
    }
}

char* reverseStr(char* s, int k)
{
    int len = strlen(s);
    for (int i = 0; i < len; i += 2 * k)
        reverse(s, i, fmin(i + k, len) - 1);
    return s;
}
