#include <limits.h>
#include <math.h>

int divide(int dividend, int divisor)
{
    if (divisor == 1)
        return dividend;
    if (dividend == divisor)
        return 1;
    if (!dividend || divisor == INT_MIN)
        return 0;
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    int sign = (dividend >= 0) == (divisor >= 0) ? 1 : -1;
    if (dividend == INT_MIN) {
        int res = (1 + divide(-(dividend + abs(divisor)), abs(divisor)));
        return sign > 0 ? res : -res;
    }

    int res = 0;
    dividend = abs(dividend);
    divisor = abs(divisor);
    while (dividend >= divisor) {
        int tmp = divisor, cnt = 1;
        while (tmp <= INT_MAX >> 1 && (tmp << 1) <= dividend) {
            cnt <<= 1;
            tmp <<= 1;
        }
        res += cnt;
        dividend -= tmp;
    }
    return sign > 0 ? res : -res;
}
