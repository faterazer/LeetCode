long long C2(long long x)
{
    return x > 0 ? x * (x - 1) / 2 : 0;
}

long long distributeCandies(int n, int limit)
{
    return C2(n + 2) - 3 * C2(n - limit + 1) + 3 * C2(n - 2 * limit) - C2(n - 3 * limit - 1);
}
