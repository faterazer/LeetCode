int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration)
{
    int res = 0, last = -1;
    for (int i = 0; i < timeSeriesSize; i++) {
        res += timeSeries[i] > last ? duration : duration - last + timeSeries[i];
        last = timeSeries[i] + duration;
    }
    return res;
}
