long long numOfTrailingZeros(long long x)
{
    long long res = 0;
    for (; x; x /= 5)
        res += x / 5;
    return res;
}

int preimageSizeFZF(int k)
{
    long long l = 0, r = 5LL * k;
    while (l <= r) {
        long long m = l + ((r - l) >> 1);
        int zeros = numOfTrailingZeros(m);

        if (zeros == k)
            return 5;
        else if (zeros < k)
            l = m + 1;
        else
            r = m - 1;
    }
    return 0;
}
