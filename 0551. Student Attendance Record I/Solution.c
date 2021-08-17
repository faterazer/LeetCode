#include <stdbool.h>

bool checkRecord(char* s)
{
    int absent = 0, late = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'L') {
            late++;
            if (late == 3)
                return false;
        } else {
            late = 0;
            if (s[i] == 'A') {
                absent++;
                if (absent == 2)
                    return false;
            }
        }
    }
    return true;
}
