#include <ctype.h>
#include <stdbool.h>

bool detectCapitalUse(char* word)
{
    int upper_cnt = 0, i;
    for (i = 0; word[i]; i++) {
        if (isupper(word[i]) && upper_cnt++ < i)
            return false;
    }
    return upper_cnt == i || upper_cnt <= 1;
}
