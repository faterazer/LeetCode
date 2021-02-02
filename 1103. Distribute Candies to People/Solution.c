#include <math.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int *returnSize)
{
    int* ret = (int*)malloc(sizeof(int) * num_people);
    *returnSize = num_people;
    int n = sqrt(0.25 + 2 * candies) - 0.5;
    int rows = n / num_people, cols = n % num_people;
    for (int i = 0; i < num_people; i++) {
        ret[i] = (i + 1) * rows + rows * (rows - 1) * num_people * 0.5;
        if (i < cols)
            ret[i] += rows * num_people + i + 1;
    }
    ret[cols] += candies - (1 + n ) * n / 2;
    return ret;
}
