#include <stdbool.h>
#include <string.h>

bool haveConflict(char** event1, int event1Size, char** event2, int event2Size)
{
    return strcmp(event1[0], event2[1]) <= 0 && strcmp(event1[1], event2[0]) >= 0;
}
