#include <memory.h>
#include <stdbool.h>

bool isCovered(int **ranges, int rangesSize, int *rangesColSize, int left, int right)
{
    int n = right - left + 1, cnt = 0;
    int range[n];
    memset(range, 0, sizeof(range));
    for (int i = 0; i < rangesSize; i++) {
        if (ranges[i][0] < left)
            cnt++;
        else if (ranges[i][0] <= right)
            range[ranges[i][0] - left]++;
        if (ranges[i][1] < left)
            cnt--;
        else if (ranges[i][1] < right)
            range[ranges[i][1] - left + 1]--;
    }
    for (int i = 0; i < n; i++) {
        cnt += range[i];
        if (!cnt)
            return false;
    }
    return true;
}
