#include <stdlib.h>
#include <string.h>

char* freqAlphabets(char *s)
{
    int size = strlen(s);
    char *ret = (char*)malloc(sizeof(int) * size);
    int idx = 0;
    char base = 'a' - 1;
    for (int i = 0; i < size;) {
        if (i + 2 < size && s[i + 2] == '#') {
            ret[idx++] = (s[i] - '0') * 10 + s[i + 1] - '0' + base;
            i += 3;
        }
        else {
            ret[idx++] = s[i] - '0' + base;
            i++;
        }
    }
    ret[idx++] = '\0';
    ret = realloc(ret, sizeof(char) * idx);
    return ret;
}
