#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows)
{
    int n = strlen(s);
    if (numRows == 1 || n <= numRows)
        return s;

    char* res = (char*)calloc(n + 1, sizeof(char));
    int tp = 0;
    for (int i = 0, a = 2 * numRows - 2, b = 0; i < numRows; i++, a -= 2, b += 2) {
        int j = i;
        res[tp++] = s[j];
        while (j < n) {
            if (a > 0 && j + a < n)
                res[tp++] = s[j + a];
            j += a;
            if (b > 0 && j + b < n)
                res[tp++] = s[j + b];
            j += b;
        }
    }
    return res;
}
