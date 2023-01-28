#include <math.h>
#include <memory.h>

int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

int countDifferentSubsequenceGCDs(int* nums, int numsSize)
{
    int res = 0, max_val = nums[0];
    for (int i = 1; i < numsSize; i++)
        max_val = fmax(max_val, nums[i]);
    int has[max_val + 1];
    memset(has, 0, sizeof(has));
    for (int i = 0; i < numsSize; i++) {
        if (!has[nums[i]]) {
            has[nums[i]] = 1;
            ++res;
        }
    }
    for (int i = 1; i * 3 <= max_val; i++) {
        if (has[i])
            continue;
        int g = 0;
        for (int j = i * 2; j <= max_val && g != j; j += i) {
            if (has[j])
                g = gcd(g, j);
        }
        if (g == i)
            ++res;
    }
    return res;
}
