#include <limits.h>

int myAtoi(char* s)
{
    int res = 0, sign = 1, i = 0;
    while (s[i] && isspace(s[i]))
        i += 1;
    if (s[i] == '+' || s[i] == '-')
        sign = s[i++] == '-' ? -1 : 1;
    while (s[i] && isdigit(s[i])) {
        int d = s[i++] - '0';
        if (sign == 1 && (INT_MAX / 10 < res || INT_MAX - d < res * 10))
            return INT_MAX;
        else if (sign == -1 && (INT_MIN / 10 > res || INT_MIN + d > res * 10))
            return INT_MIN;
        res = res * 10 + d * sign;
    }
    return res;
}
