#include <stdbool.h>

bool canTransform(char* start, char* end)
{
    int i = 0, j = 0;
    while (start[i] && end[j]) {
        while (start[i] && start[i] == 'X')
            ++i;
        while (end[j] && end[j] == 'X')
            ++j;
        if (start[i] && end[j]) {
            if (start[i] != end[j])
                return false;
            if (start[i] == 'L' && i < j)
                return false;
            if (start[i] == 'R' && i > j)
                return false;
            ++i;
            ++j;
        }
    }
    while (start[i]) {
        if (start[i] != 'X')
            return false;
        ++i;
    }
    while (end[j]) {
        if (end[j] != 'X')
            return false;
        ++j;
    }
    return true;
}
