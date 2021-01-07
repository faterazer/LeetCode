#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    char *s1 = *(char**)a;
    char *s2 = *(char**)b;
    char *as = strchr(s1, ' ') + 1, *bs = strchr(s2, ' ') + 1;
    int r = strcmp(as, bs);
    return r ? r : strcmp(s1, s2);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **reorderLogFiles(char **logs, int logsSize, int *returnSize)
{
    *returnSize = logsSize;
    int last = logsSize - 1;
    for (int i = last; i >= 0; i--) {
        char *s = strchr(logs[i], ' ');
        if (isdigit(*(s + 1))) {
            char *tmp = logs[last];
            logs[last--] = logs[i];
            logs[i] = tmp;
        }
    }
    qsort(logs, last + 1, sizeof(logs[0]), cmp);
    return logs;
}
