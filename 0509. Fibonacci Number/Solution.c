#include <math.h>

int fib(int n)
{
    double sqrt5 = sqrt(5);
    double fibn = pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
    return fibn / sqrt5;
}
