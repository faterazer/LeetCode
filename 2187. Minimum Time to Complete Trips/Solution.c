#include <math.h>

long long minimumTime(int* time, int timeSize, int totalTrips)
{
    long long min_val = time[0];
    for (int i = 0; i < timeSize; i++)
        min_val = fmin(min_val, time[i]);

    long long lo = min_val, hi = min_val * totalTrips;
    while (lo < hi) {
        long long mid = lo + ((hi - lo) >> 1);
        long long trips = 0;
        for (int i = 0; i < timeSize; i++)
            trips += mid / time[i];
        if (trips < totalTrips)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}
