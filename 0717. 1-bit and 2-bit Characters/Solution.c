#include <stdbool.h>

bool isOneBitCharacter(int *bits, int bitsSize)
{
    int ones = 0;
    for (int i = bitsSize - 2; i >= 0 && bits[i]; i--)
        ones++;
    return ones % 2 == 0;
}
