#include <math.h>

int leastInterval(char* tasks, int tasksSize, int n)
{
    int cnt[26] = { 0 };
    for (int i = 0; i < tasksSize; i++)
        cnt[tasks[i] - 'A']++;

    int max_val = 0;
    for (int i = 0; i < 26; i++)
        max_val = fmax(max_val, cnt[i]);

    int max_cnt = 0;
    for (int i = 0; i < 26; i++)
        if (cnt[i] == max_val)
            ++max_cnt;

    return fmax(tasksSize, (max_val - 1) * (n + 1) + max_cnt);
}
