#include <math.h>

int countDigitOne(int n)
{
    long long power = 1;
    int res = 0, tail = 0;
    for (; n; n /= 10) {
        tail = n % 10 * power + tail;
        res += n / 10 * power + fmin(fmax(tail - power + 1, 0), power);
        power *= 10;
    }
    return res;
}
