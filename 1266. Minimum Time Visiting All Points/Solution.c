#include <math.h>

int minTimeToVisitAllPoints(int **points, int pointsSize, int *pointsColSize)
{
    int cost = 0;
    for (int i = 1; i < pointsSize; i++)
        cost += fmax(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
    return cost;
}
