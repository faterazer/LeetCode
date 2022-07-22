#include <stdbool.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

bool dfs(int* matchsticks, int size, int idx, int cur, int side_len, int remain, int state)
{
    if (remain == 0)
        return true;
    if (cur == side_len)
        return dfs(matchsticks, size, 0, 0, side_len, remain - 1, state);
    for (int i = idx; i < size; ++i) {
        if (state & (1 << i))
            continue;
        if (cur + matchsticks[i] > side_len)
            continue;
        if (dfs(matchsticks, size, i + 1, cur + matchsticks[i], side_len, remain, state | (1 << i)))
            return true;
        while (i < size - 1 && matchsticks[i] == matchsticks[i + 1])
            ++i;
    }
    return false;
}

bool makesquare(int* matchsticks, int matchsticksSize)
{
    int all_len = 0;
    for (int i = 0; i < matchsticksSize; ++i)
        all_len += matchsticks[i];
    if (all_len % 4)
        return false;

    int side_len = all_len / 4;
    for (int i = 0; i < matchsticksSize; ++i)
        if (matchsticks[i] > side_len)
            return false;

    qsort(matchsticks, matchsticksSize, sizeof(int), cmp);
    return dfs(matchsticks, matchsticksSize, 0, 0, side_len, 4, 0);
}
