int findNthDigit(int n)
{
    int digits = 1, nums = 9, base = 0;
    while (n / digits > nums) {
        n -= digits * nums;
        ++digits;
        nums *= 10;
        base = base * 10 + 9;
    }
    int res = base + n / digits;
    if (n % digits)
        ++res;
    for (int i = 0; i < (digits - n % digits) % digits; i++)
        res /= 10;
    return res % 10;
}
