#include <math.h>

double average(int *salary, int salarySize)
{
    int sum = 0, mx = salary[0], mn = salary[0];
    for (int i = 0; i < salarySize; i++) {
        sum += salary[i];
        mx = fmax(salary[i], mx);
        mn = fmin(salary[i], mn);
    }
    return (double)(sum - mx - mn) / (salarySize - 2);
}
