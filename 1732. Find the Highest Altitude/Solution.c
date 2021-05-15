#include <math.h>

int largestAltitude(int *gain, int gainSize)
{
    int res = 0, altitude = 0;
    for (int i = 0; i < gainSize; i++) {
        altitude += gain[i];
        res = fmax(res, altitude);
    }
    return res;
}
