#include <math.h>

double calculateTax(int** brackets, int bracketsSize, int* bracketsColSize, int income)
{
    double tax = 0.0, prev = 0.0;
    for (int i = 0; i < bracketsSize; i++) {
        int upper = brackets[i][0], percent = brackets[i][1];
        tax += (fmin(income, upper) - prev) * percent / 100;
        prev = upper;
        if (income <= upper)
            break;
    }
    return tax;
}
