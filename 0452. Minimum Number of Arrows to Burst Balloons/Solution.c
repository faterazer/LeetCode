#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    int _a = (*(int**)a)[1], _b = (*(int**)b)[1];
    return _a < _b ? -1 : 1;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize)
{
    qsort(points, pointsSize, sizeof(int*), cmp);
    int res = 1, pos = points[0][1];
    for (int i = 1; i < pointsSize; i++) {
        if (points[i][0] > pos) {
            pos = points[i][1];
            ++res;
        }
    }
    return res;
}
