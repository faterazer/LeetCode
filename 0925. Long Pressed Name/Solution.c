#include <string.h>

bool isLongPressedName(char *name, char *typed)
{
    int i = 0, j = 0, nameSize = strlen(name), typedSize = strlen(typed);

    for (; j < typedSize; j++) {
        if (name[i] == typed[j])
            i++;
        else if (j == 0 || typed[j] != typed[j - 1])
            return false;
    }
    return i == nameSize;
}
