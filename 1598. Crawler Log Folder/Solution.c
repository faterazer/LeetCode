#include <math.h>
#include <string.h>

int minOperations(char **logs, int logsSize)
{
    int res = 0;
    for (int i = 0; i < logsSize; i++) {
        if (strcmp(logs[i], "../") == 0)
            res = fmax(0, res - 1);
        else if (strcmp(logs[i], "./") != 0)
            res++;
    }
    return res;
}
