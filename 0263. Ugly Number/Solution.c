#include <stdbool.h>

bool isUgly(int n)
{
    if (n <= 0)
        return false;
    int factors[3] = {2, 3, 5};
    for (int i = 0; i < 3; i++)
        while (n % factors[i] == 0)
            n /= factors[i];
    return n == 1;
}
