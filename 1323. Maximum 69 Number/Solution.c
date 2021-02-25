#include <math.h>

int maximum69Number(int num)
{
    int i = 0;
    for (int n = num, j = 1; n; n /= 10, j *= 10)
        if (n % 10 == 6)
            i = j;
    return num + 3 * i;
}
