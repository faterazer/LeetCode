int minTime(char* s, int* order, int orderSize, int k)
{
    int n = orderSize;
    long long cnt = 1LL * n * (n + 1) / 2;
    if (cnt < k)
        return -1;
    
    int prev[n], next[n];
    for (int i = 0; i < n; ++i) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    for (int t = n - 1; t >= 0; --t) {
        int i = order[t];
        int l = prev[i], r = next[i];
        cnt -= 1LL * (i - l) * (r - i);
        if (cnt < k)
            return t;
        if (l >= 0)
            next[l] = r;
        if (r < n)
            prev[r] = l;
    }
    return -1;
}
