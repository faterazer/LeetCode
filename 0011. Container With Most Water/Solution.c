#include <math.h>

int maxArea(int* height, int heightSize)
{
    int l = 0, r = heightSize - 1;
    int res = 0;
    while (l < r) {
        if (height[l] <= height[r]) {
            res = fmax(res, (r - l) * height[l]);
            l += 1;
        } else {
            res = fmax(res, (r - l) * height[r]);
            r -= 1;
        }
    }
    return res;
}
