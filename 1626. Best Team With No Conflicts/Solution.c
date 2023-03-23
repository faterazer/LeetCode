#include <math.h>
#include <stdlib.h>
#include <string.h>

int lowbit(int x)
{
    return x & -x;
}

int query(const int* arr, int idx)
{
    int res = 0;
    for (; idx > 0; idx -= lowbit(idx))
        res = fmax(res, arr[idx]);
    return res;
}

void update(int* arr, int arr_len, int idx, int val)
{
    for (; idx < arr_len; idx += lowbit(idx))
        arr[idx] = fmax(arr[idx], val);
}

int cmp(const void* pa, const void* pb)
{
    int *a = (int*)pa, *b = (int*)pb;
    if (a[0] == b[0])
        return a[1] - b[1];
    return a[0] - b[0];
}

int bestTeamScore(int* scores, int scoresSize, int* ages, int agesSize)
{
    int n = scoresSize;
    int players[n][2];
    for (int i = 0; i < n; i++) {
        players[i][0] = scores[i];
        players[i][1] = ages[i];
    }
    qsort(players, n, sizeof(players[0]), cmp);

    int len = 1001, f[len];
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++)
        update(f, len, players[i][1], query(f, players[i][1]) + players[i][0]);
    return query(f, len - 1);
}
