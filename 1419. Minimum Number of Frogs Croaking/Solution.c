#include <math.h>
#include <string.h>

int minNumberOfFrogs(char* croakOfFrogs)
{
    int cnt[5] = { 0 }, res = 0, frogs = 0;
    char* croak = "croak";
    for (int i = 0; croakOfFrogs[i]; i++) {
        int idx = strchr(croak, croakOfFrogs[i]) - croak;
        ++cnt[idx];
        if (idx == 0)
            res = fmax(res, ++frogs);
        else if (--cnt[idx - 1] < 0)
            return -1;
        else if (idx == 4)
            --frogs;
    }
    return frogs == 0 ? res : -1;
}
