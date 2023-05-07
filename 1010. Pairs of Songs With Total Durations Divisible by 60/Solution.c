int numPairsDivisibleBy60(int* time, int timeSize)
{
    int res = 0, cnt[60] = { 0 };
    for (int i = 0; i < timeSize; i++) {
        res += cnt[(60 - time[i] % 60) % 60];
        cnt[time[i] % 60]++;
    }
    return res;
}
