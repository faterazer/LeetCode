#include <stdbool.h>

bool checkDistances(char* s, int* distance, int distanceSize)
{
    int last[26] = { 0 };
    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (last[c] && i - last[c] != distance[c])
            return false;
        last[c] = i + 1;
    }
    return true;
}
