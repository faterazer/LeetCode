#include <math.h>

long long minimumPerimeter(long long neededApples)
{
    long long n = cbrt(neededApples / 4.0);
    if (2 * n * (n + 1) * (2 * n + 1) < neededApples)
        n++;
    return 8 * n;
}
