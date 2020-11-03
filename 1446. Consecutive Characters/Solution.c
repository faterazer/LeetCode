#include <math.h>

int maxPower(char *s)
{
    int ret = 1, power = 1;
    for (int i = 1; s[i]; i++) {
        if (s[i] == s[i - 1])
            power++;
        else {
            ret = fmax(ret, power);
            power = 1;
        }
    }
    return fmax(ret, power);
}
