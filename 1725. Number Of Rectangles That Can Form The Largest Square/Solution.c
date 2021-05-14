#include <math.h>

int countGoodRectangles(int **rectangles, int rectanglesSize, int *rectanglesColSize)
{
    int max = 0, cnt = 0, side;
    for (int i = 0; i < rectanglesSize; i++) {
        side = fmin(rectangles[i][0], rectangles[i][1]);
        if (max < side) {
            max = side;
            cnt = 1;
        }
        else if (max == side)
            cnt++;
    }
    return cnt;
}
