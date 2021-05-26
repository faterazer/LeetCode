#include <limits.h>
#include <stdlib.h>

int nearestValidPoint(int x, int y, int **points, int pointsSize, int *pointsColSize)
{
    int res = -1, dist = INT_MAX;
    for (int i = 0; i < pointsSize; i++) {
        int xx = points[i][0], yy = points[i][1];
        if (xx == x || yy == y) {
            int tmp = abs(xx - x) + abs(yy - y);
            if (tmp < dist) {
                dist = tmp;
                res = i;
            }
        }
    }
    return res;
}
