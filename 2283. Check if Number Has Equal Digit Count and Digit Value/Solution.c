#include <stdbool.h>

bool digitCount(char* num)
{
    int cnt[10] = {0};
    for (int i = 0; num[i]; i++)
        cnt[num[i] - '0']++;
    for (int i = 0; num[i]; i++)
        if (cnt[i] != num[i] - '0')
            return false;
    return true;
}
