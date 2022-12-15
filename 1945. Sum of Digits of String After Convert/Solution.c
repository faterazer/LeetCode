int digitSum(int x)
{
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int getLucky(char* s, int k)
{
    int res = 0;
    for (int i = 0; s[i]; i++)
        res += digitSum(s[i] - 'a' + 1);
    for (int i = 2; i <= k; i++)
        res = digitSum(res);
    return res;
}
