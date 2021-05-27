int hammingDistance(int x, int y)
{
    int res = 0;
    for (x ^= y; x; x &= x - 1)
        res++;
    return res;
}
