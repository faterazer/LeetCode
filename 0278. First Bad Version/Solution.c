#include <stdbool.h>

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int l = 1, r = n, m;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (isBadVersion(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}
