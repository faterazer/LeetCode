#include <stdbool.h>
#include <string.h>

bool isVowel(char c)
{
    char vowels[] = "aeiouAEIOU";
    for (int i = 0; vowels[i]; i++)
        if (vowels[i] == c)
            return true;
    return false;
}

void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

char* reverseVowels(char* s)
{
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        while (i < j && !isVowel(s[i]))
            i++;
        while (i < j && !isVowel(s[j]))
            j--;
        if (i < j) {
            swap(s + i, s + j);
            i++;
            j--;
        }
    }
    return s;
}
