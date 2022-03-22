#include <stdbool.h>
#include <string.h>

bool winnerOfGame(char* colors)
{
    int Alice_count = 0, Bob_count = 0, size = strlen(colors);
    for (int i = 1; i < size - 1; ++i) {
        if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1]) {
            if (colors[i] == 'A')
                Alice_count += 1;
            else
                Bob_count += 1;
        }
    }
    return Alice_count > Bob_count;
}
