int countEven(int num)
{
    int tmp = num, sum = 0;
    while (tmp) {
        sum += tmp % 10;
        tmp /= 10;
    }
    int res = num / 10 * 5 - 1;
    if (sum & 1)
        return res + (num % 10 + 1) / 2;
    else
        return res + num % 10 / 2 + 1;
}
