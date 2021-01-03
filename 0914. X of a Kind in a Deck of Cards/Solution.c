#include <math.h>
#include <stdbool.h>

int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

bool hasGroupsSizeX(int *deck, int deckSize)
{
    int hash[10000] = {0};
    for (int i = 0; i < deckSize; i++)
        hash[deck[i]]++;
    int res = 0;
    for (int i = 0; i < 10000; i++)
        if (hash[i])
            res = gcd(res, hash[i]);
    return res > 1;
}
