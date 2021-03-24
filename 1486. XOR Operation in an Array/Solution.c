int xorOperation_MK1(int n, int start)
{
    int res = 0;
    for (int i = 0; i < n; i++, start += 2)
        res ^= start;
    return res;
}

int helper(int n, int start)
{
    if (start & 1)
        return (start - 1) ^ helper1(n + 1, start - 1);
    if (n % 2 == 0)
        return (n >> 1) & 1;
    else
        return (n >> 1) & 1 ^ (start + n - 1);
}

// 时间复杂度：O(1)
int xorOperation_MK2(int n, int start)
{
    int res = helper(n, start >> 1) << 1;
    if (n & start & 1)
        res |= 1;
    return res;
}
