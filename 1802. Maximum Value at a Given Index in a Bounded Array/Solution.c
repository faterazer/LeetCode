#include <math.h>

long long countSum(int n, int index, long long val)
{
    long long lc = index, rc = n - index - 1;
    long long left_sum = (2 * val - lc - 1) * lc / 2;
    if (val <= lc + 1)
        left_sum = (val * val - 3 * val) / 2 + lc + 1;
    long long right_sum = (2 * val - rc - 1) * rc / 2;
    if (val <= rc + 1)
        right_sum = (val * val - 3 * val) / 2 + rc + 1;
    return left_sum + val + right_sum;
}

/**
 * Time complexity: O(lg(maxSum))
 * Space complexity: O(1)
 */
int maxValue_MK1(int n, int index, int maxSum)
{
    int left = 1, right = maxSum;
    while (left < right) {
        int mid = left + ((right + 1 - left) >> 1);
        long long s = countSum(n, index, mid);
        if (s <= maxSum)
            left = mid;
        else
            right = mid - 1;
    }
    return left;
}

/**
 * Time complexity: O(lg(maxSum))
 * Space complexity: O(1)
 */
int maxValue_MK2(int n, int index, int maxSum)
{
    double left = index, right = n - index - 1;
    if (left > right) {
        double tmp = left;
        left = right;
        right = tmp;
    }

    double upper = left * left + 3 * left + right + 1;
    if (upper >= maxSum) {
        double a = 1, b = -2, c = left + right + 2 - maxSum;
        return floor((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
    }

    upper = ((double)2 * (right + 1) - left - 1) * left / 2 + (right + 1) + ((right + 1) * (right + 1) - 3 * (right + 1)) / 2 + right + 1;
    if (upper >= maxSum) {
        double a = 1.0 / 2;
        double b = left + 1 - 3.0 / 2;
        double c = right + 1 + (-left - 1) * left / 2 - maxSum;
        return (int)floor((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
    } else {
        double a = left + right + 1;
        double b = (-left * left - left - right * right - right) / 2 - maxSum;
        return (int)floor(-b / a);
    }
}
