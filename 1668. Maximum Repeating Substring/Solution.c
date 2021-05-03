#include <math.h>
#include <string.h>

int maxRepeating(char *sequence, char *word)
{
    int n = strlen(sequence), m = strlen(word), res = 0;
    int next[n];
    next[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && word[i % m] != word[j % m])
            j = next[j - 1];
        if (word[i % m] == word[j % m])
            j++;
        next[i] = j;
    }
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && sequence[i] != word[j % m])
            j = next[j - 1];
        if (sequence[i] == word[j % m])
            j++;
        res = fmax(res, j / m);
    }
    return res;
}
