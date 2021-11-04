#include <stdbool.h>

int sqrtByLinearSearch(int n)
{
    int r = 1;
    while (r <= n / r)
        r++;
    return r - 1;
}

int sqrtByBinarySearch(int n)
{
    if (n == 1)
        return n;
    int l = 1, r = n / 2, m;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (m < n / m) {
            l = m + 1;
        } else if (m > n / m) {
            r = m - 1;
        } else {
            return m;
        }
    }
    return r;
}

int sqrtByNewton(int num)
{
    int r = num / 2 + 1;
    while (r > num / r) {
        r = (r + num / r) / 2;
    }
    return r;
}

bool isPerfectSquare(int num)
{
    int root = sqrtByNewton(num);
    return num % root == 0 && num / root == root;
}
