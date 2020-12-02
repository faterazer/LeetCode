#include <math.h>

double area(int *a, int *b, int *c)
{
    return 0.5 * fabs((a[0] - b[0]) * (c[1] - b[1]) - (a[1] - b[1]) * (c[0] - b[0]));
}

double largestTriangleArea(int **points, int pointsSize, int *pointsColSize)
{
    double res = 0.0;
    for (int i = 0; i < pointsSize - 2; i++)
        for (int j = i + 1; j < pointsSize - 1; j++)
            for (int k = j + 1; k < pointsSize; k++)
                res = fmax(res, area(points[i], points[j], points[k]));
    return res;
}
