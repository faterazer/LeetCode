#include <stdbool.h>

static int directions[][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

bool isRobotBounded(char* instructions)
{
    int x = 0, y = 0, d = 0;
    for (int i = 0; instructions[i]; i++) {
        if (instructions[i] == 'L')
            d = (d + 3) % 4;
        else if (instructions[i] == 'R')
            d = (d + 1) % 4;
        else {
            x += directions[d][0];
            y += directions[d][1];
        }
    }
    return (x == 0 && y == 0) || d > 0;
}
