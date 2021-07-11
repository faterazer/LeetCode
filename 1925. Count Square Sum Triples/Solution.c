#include <math.h>

int countTriples(int n)
{
    int res = 0, c;
    for (int a = 3; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            c = (int)sqrt(a * a + b * b);
            if (c <= n && c * c == a * a + b * b)
                res += a == b ? 1 : 2;
        }
    }
    return res;
}
