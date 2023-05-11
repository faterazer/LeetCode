int smallestRepunitDivByK(int k)
{
    if (k % 2 == 0 || k % 5 == 0)
        return -1;
    for (int i = 1, x = 1 % k;; i++) {
        if (x == 0)
            return i;
        x = (x * 10 + 1) % k;
    }
}
