#include <math.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b)
{
    return *(char*)a - *(char*)b;
}

char* orderlyQueue(char* s, int k)
{
    int size = strlen(s);
    if (k > 1) {
        qsort(s, size, sizeof(char), cmp);
        return s;
    } else {
        int offset = 0, i = 0, j = 1;
        while (offset < size && i < size && j < size) {
            if (s[(i + offset) % size] == s[(j + offset) % size])
                ++offset;
            else {
                (s[(i + offset) % size] > s[(j + offset) % size]) ? (i = i + offset + 1) : (j = j + offset + 1);
                if (i == j)
                    ++i;
                offset = 0;
            }
        }
        i = fmin(i, j);
        char* res = (char*)malloc(sizeof(char) * (size + 1));
        strcpy(res, s + i);
        strncpy(res + size - i, s, i);
        res[size] = '\0';
        return res;
    }
}
