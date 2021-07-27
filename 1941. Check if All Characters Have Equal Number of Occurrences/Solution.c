#include <stdbool.h>

bool areOccurrencesEqual(char *s)
{
    int map[26] = {0};
    for (int i = 0; s[i]; i++)
        map[s[i] - 'a']++;
    int last = 0;
    for (int i = 0; i < 26; i++) {
        if (map[i]) {
            if (!last)
                last = map[i];
            else if (map[i] != last)
                return false;
        }
    }
    return true;
}
