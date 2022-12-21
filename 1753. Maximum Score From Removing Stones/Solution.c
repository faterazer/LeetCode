#include <math.h>

int maximumScore(int a, int b, int c)
{
    int sum = a + b + c, max_val = fmax(a, fmax(b, c));
    return fmin(sum - max_val, sum / 2);
}
