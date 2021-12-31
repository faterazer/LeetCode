#include <math.h>
#include <stdbool.h>

bool checkPerfectNumber(int num)
{
    if (num <= 1)
        return false;
    int res = 1, n = sqrt(num);
    for (int i = 2; i <= n; i++)
        if (num % i == 0)
            res += i + num / i;
    return res == num;
}
