#include <math.h>

int trap(int* height, int heightSize)
{
    int res = 0, pre_max = 0, suf_max = 0, i = 0, j = heightSize - 1;
    while (i < j) {
        pre_max = fmax(pre_max, height[i]);
        suf_max = fmax(suf_max, height[j]);
        res += pre_max < suf_max ? pre_max - height[i++] : suf_max - height[j--];
    }
    return res;
}
