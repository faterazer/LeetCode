#include <stdbool.h>

bool checkIfPangram(char *sentence)
{
    unsigned seen = 0;
    for (int i = 0; sentence[i]; i++)
        seen |= 1 << (sentence[i] - 'a');
    return seen == 0x3ffffff;
}
