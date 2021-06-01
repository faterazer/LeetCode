#include <stdbool.h>

bool squareIsWhite(char *coordinates)
{
    int x = coordinates[0] - 'a';
    int y = coordinates[1] - '1';
    return (x + y) % 2;
}
