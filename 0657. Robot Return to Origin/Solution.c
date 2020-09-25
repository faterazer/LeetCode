#include <stdbool.h>

bool judgeCircle(char *moves)
{
    int x = 0, y = 0;
    for (int i = 0; moves[i]; i++) {
        switch (moves[i]) {
            case 'R':
                x += 1;
                break;
            case 'L':
                x -= 1;
                break;
            case 'U':
                y += 1;
                break;
            case 'D':
                y -= 1;
                break;
        }
    }
    return x == 0 && y == 0;
}
