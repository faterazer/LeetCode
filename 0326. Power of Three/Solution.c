#include <stdbool.h>

bool isPowerOfThree_MK1(int n)
{
    if (n <= 0)
        return false;
    while (n % 3 == 0)
        n /= 3;
    return n == 1;
}

bool isPowerOfThree_MK2(int n)
{
    return n > 0 && 1162261467 % n == 0;
}
