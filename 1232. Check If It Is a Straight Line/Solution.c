#include <stdbool.h>

bool checkStraightLine(int **coordinates, int coordinatesSize, int *coordinatesColSize)
{
    int A = coordinates[1][1] - coordinates[0][1], B = coordinates[1][0] - coordinates[0][0];
    for (int i = 2; i < coordinatesSize; i++)
        if ((coordinates[i][1] - coordinates[0][1]) * B != (coordinates[i][0] - coordinates[0][0]) * A)
            return false;
    return true;
}
