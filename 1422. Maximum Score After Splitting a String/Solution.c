#include <math.h>

int maxScore(char *s)
{
    int leftSum = s[0] == '0';
    int rightSum = 0, res, len;
    for (len = 1; s[len]; len++)
        rightSum += s[len] == '1';
    res = leftSum + rightSum;
    len -= 1;
    for (int i = 1; i < len; i++) {
        leftSum += s[i] == '0';
        rightSum -= s[i] == '1';
        res = fmax(res, leftSum + rightSum);
    }
    return res;
}
