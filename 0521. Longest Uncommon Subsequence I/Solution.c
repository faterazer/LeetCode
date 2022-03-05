#include <math.h>
#include <string.h>

int findLUSlength(char* a, char* b)
{
    int an = strlen(a), bn = strlen(b);
    return an == bn && strcmp(a, b) == 0 ? -1 : fmax(an, bn);
}
