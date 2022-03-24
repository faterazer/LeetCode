#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int numRescueBoats(int* people, int peopleSize, int limit)
{
    qsort(people, peopleSize, sizeof(int), cmp);
    int l = 0, r = peopleSize - 1, res = 0;
    while (l <= r) {
        if (people[l] + people[r] <= limit) {
            l += 1;
            r -= 1;
        } else
            r -= 1;
        res += 1;
    }
    return res;
}
