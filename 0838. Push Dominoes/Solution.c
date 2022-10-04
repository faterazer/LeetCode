#include <string.h>

char* pushDominoes(char* dominoes)
{
    int n = strlen(dominoes), i = 0;
    char left = 'L';
    while (i < n) {
        int j = i;
        while (j < n && dominoes[j] == '.')
            ++j;
        char right = dominoes[j] ? dominoes[j] : 'R';
        if (left == right) {
            for (; i < j; i++)
                dominoes[i] = left;
        } else if (left == 'R' && right == 'L') {
            for (int k = j - 1; i < k; i++, k--) {
                dominoes[i] = left;
                dominoes[k] = right;
            }
        }
        left = right;
        i = j + 1;
    }
    return dominoes;
}
