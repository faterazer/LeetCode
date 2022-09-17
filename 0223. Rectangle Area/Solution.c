#include <math.h>

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    int area = (ay2 - ay1) * (ax2 - ax1) + (by2 - by1) * (bx2 - bx1);
    int overlap_width = fmin(ax2, bx2) - fmax(ax1, bx1), overlap_height = fmin(ay2, by2) - fmax(ay1, by1);
    return area - fmax(overlap_width, 0) * fmax(overlap_height, 0);
}
