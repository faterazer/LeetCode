#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **summaryRanges(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 0;
    char **ret = NULL;
    char buf[32] = {0};
    for (int i = 0; i < numsSize;) {
        int j = i + 1;
        while (j < numsSize && nums[j] == nums[j - 1] + 1)
            j++;
        if (i != j - 1)
            sprintf(buf, "%d->%d", nums[i], nums[j - 1]);
        else
            sprintf(buf, "%d", nums[i]);
        int len = strlen(buf);
        char *s = (char*)malloc(sizeof(char) * (len + 1));
        memset(s, 0, sizeof(char) * (len + 1));
        strcpy(s, buf);
        ret = (char**)realloc(ret, sizeof(char*) * ++(*returnSize));
        ret[(*returnSize) - 1] = s;
        i = j;
    }
    return ret;
}
