#include <stdbool.h>

/* The knows API is defined for you. */
bool knows(int a, int b);

int findCelebrity(int n)
{
    int celebrity = 0;
    for (int i = 1; i < n; i++)
        if (knows(celebrity, i))
            celebrity = i;

    for (int i = 0; i < n; i++) {
        if (i == celebrity)
            continue;
        if (!knows(i, celebrity) || knows(celebrity, i))
            return -1;
    }
    return celebrity;
}
