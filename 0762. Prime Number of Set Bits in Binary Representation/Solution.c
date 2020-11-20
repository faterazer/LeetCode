int countOneBits(int n)
{
    int cnt = 0;
    while (n) {
        cnt++;
        n &= n - 1;
    }
    return cnt;
}

int countPrimeSetBits(int L, int R)
{
    int cnt = 0;
    for (int i = L; i<= R; i++)
            cnt += 665772 >> countOneBits(i) & 1;   // 665772 的二进制表示上，所有的质数位都是 1
    return cnt;
}
