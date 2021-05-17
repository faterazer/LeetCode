#include <math.h>

int countBalls(int lowLimit, int highLimit)
{
    int count[46] = {0}, sum, res = 0;
    for (int i = lowLimit; i <= highLimit; i++) {
        sum = 0;
        for (int j = i; j; j /= 10)
            sum += j % 10;
        count[sum]++;
    }
    for (int i = 0; i < 46; i++)
        res = fmax(res, count[i]);
    return res;
}
