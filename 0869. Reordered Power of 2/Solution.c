#include <math.h>
#include <stdbool.h>

int counter(int x)
{
    int res = 0;
    while (x) {
        res += pow(10, x % 10);
        x /= 10;
    }
    return res;
}

bool reorderedPowerOf2(int n)
{
    int c = counter(n);
    for (int i = 0; i < 31; ++i)
        if (counter(1 << i) == c)
            return true;
    return false;
}
