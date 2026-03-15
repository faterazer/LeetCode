char findKthBit_MK1(int n, int k)
{
    if (n == 1)
        return '0';
    int mid = 1 << (n - 1);
    if (k == mid)
        return '1';
    else if (k < mid)
        return findKthBit_MK1(n - 1, k);
    else
        return '1' - findKthBit_MK1(n - 1, (1 << n) - k);
}

char findKthBit_MK2(int n, int k)
{
    if (k & 1)
        return '0' + k / 2 % 2;
    k /= k & -k;
    return '1' - k / 2 % 2;
}
