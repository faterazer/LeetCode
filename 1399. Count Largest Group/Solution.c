#include <math.h>

int sumOfDigits(int n)
{
    int sum = 0;
    for (; n; n /= 10)
        sum += n % 10;
    return sum;
}

int countLargestGroup(int n)
{
    int hash[37] = {0};
    int max = 0, res = 0;
    for (int i = 1; i <= n; i++)
        max = fmax(max, ++hash[sumOfDigits(i)]);
    for (int i = 1; i < 37; i++)
        res += hash[i] == max;
    return res;
}
