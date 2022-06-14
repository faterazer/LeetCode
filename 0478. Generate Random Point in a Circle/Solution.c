#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double radius, x_center, y_center;
} Solution;

Solution* solutionCreate(double radius, double x_center, double y_center)
{
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->radius = radius;
    obj->x_center = x_center;
    obj->y_center = y_center;
    return obj;
}

double* solutionRandPoint(Solution* obj, int* retSize)
{
    double r = sqrt((double)rand() / RAND_MAX);
    double theta = (double)rand() / RAND_MAX * 2 * M_PI;
    double *res = (double*)malloc(sizeof(double) * 2);
    res[0] = obj->x_center + r * cos(theta) * obj->radius;
    res[1] = obj->y_center + r * sin(theta) * obj->radius;
    *retSize = 2;
    return res;
}

void solutionFree(Solution* obj)
{
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(radius, x_center, y_center);
 * double* param_1 = solutionRandPoint(obj, retSize);

 * solutionFree(obj);
*/
